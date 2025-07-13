import requests
import os
import json
from datetime import datetime
import subprocess
from dotenv import load_dotenv

# Load from .env
load_dotenv()

LEETCODE_SESSION = os.getenv("LEETCODE_SESSION")
CSRFTOKEN = os.getenv("CSRFTOKEN")
USERNAME = os.getenv("LEETCODE_USERNAME")

HEADERS = {
    "Cookie": f"LEETCODE_SESSION={LEETCODE_SESSION}; csrftoken={CSRFTOKEN}",
    "Referer": "https://leetcode.com",
    "X-CSRFToken": CSRFTOKEN,
    "User-Agent": "Mozilla/5.0"
}

GRAPHQL_URL = "https://leetcode.com/graphql"
SUBMISSION_QUERY = """
query recentAcSubmissions($username: String!, $limit: Int!) {
  recentAcSubmissionList(username: $username, limit: $limit) {
    id
    title
    titleSlug
    timestamp
  }
}
"""

CODE_QUERY = """
query submissionDetails($submissionId: Int!) {
  submissionDetails(submissionId: $submissionId) {
    code
    lang {
      name
    }
  }
}
"""

def fetch_recent_submission():
    variables = {"username": USERNAME, "limit": 1}
    response = requests.post(GRAPHQL_URL, headers=HEADERS, json={
        "query": SUBMISSION_QUERY,
        "variables": variables
    })

    if response.status_code != 200:
        print("❌ Error fetching submissions. Check your cookies.")
        return None

    data = response.json()
    if not data.get("data"):
        print("❌ No data returned. Your session might be expired.")
        return None

    return data["data"]["recentAcSubmissionList"][0]

def fetch_submission_code(submission_id):
    variables = {"submissionId": submission_id}
    response = requests.post(GRAPHQL_URL, headers=HEADERS, json={
        "query": CODE_QUERY,
        "variables": variables
    })

    try:
        data = response.json()
    except Exception as e:
        print("❌ Failed to parse JSON:", e)
        print("🔻 Raw response:", response.text)
        return None

    if "errors" in data:
        print("❌ GraphQL error occurred:")
        for err in data["errors"]:
            print(" -", err.get("message", "No message"))
        print("🔻 Full response:", json.dumps(data, indent=2))
        return None

    if "data" not in data or not data["data"]["submissionDetails"]:
        print("❌ 'submissionDetails' missing. Likely an auth issue or invalid submission ID.")
        print("🔻 Full response:", json.dumps(data, indent=2))
        return None

    return data["data"]["submissionDetails"]



def save_code(sub, detail):
    lang = detail["lang"]["name"]
    ext = {
        "cpp": "cpp", "python": "py", "python3": "py", "java": "java",
        "c": "c", "csharp": "cs", "javascript": "js", "typescript": "ts"
    }.get(lang, "txt")

    today = datetime.now().strftime("%Y-%m-%d")
    folder = f"solutions/{today}"
    os.makedirs(folder, exist_ok=True)

    filename = f"{folder}/{sub['id']}_{sub['titleSlug']}.{ext}"
    with open(filename, "w", encoding="utf-8") as f:
        f.write(detail["code"])

    return filename

def git_push(filename):
    subprocess.run(["git", "add", filename])
    subprocess.run(["git", "commit", "-m", f"Add solution: {os.path.basename(filename)}"])
    subprocess.run(["git", "push"])

def main():
    sub = fetch_recent_submission()
    if not sub:
        return
    detail = fetch_submission_code(sub["id"])
    if not detail:
        print("❌ Failed to fetch submission code")
        return
    filename = save_code(sub, detail)
    git_push(filename)
    print(f"✅ Pushed: {filename}")

if __name__ == "__main__":
    main()
