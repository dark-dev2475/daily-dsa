from flask import Flask, request, jsonify
from flask_cors import CORS
import subprocess
import os
import threading
import time

app = Flask(__name__)
CORS(app)  # Allow cross-origin requests from the extension

# Global variable to track if sync is running
sync_running = False

@app.route('/trigger-sync', methods=['POST'])
def trigger_sync():
    global sync_running
    
    if sync_running:
        return jsonify({
            'success': False,
            'message': 'Sync already running'
        })
    
    sync_running = True
    
    try:
        # Run the sync script in a separate thread
        def run_sync():
            global sync_running
            try:
                result = subprocess.run(
                    ['python', 'sync_leetcode.py'],
                    capture_output=True,
                    text=True,
                    cwd=os.getcwd()
                )
                
                if result.returncode == 0:
                    print("✅ Sync completed successfully")
                else:
                    print(f"❌ Sync failed: {result.stderr}")
                    
            except Exception as e:
                print(f"❌ Error running sync: {e}")
            finally:
                sync_running = False
        
        # Start sync in background thread
        thread = threading.Thread(target=run_sync)
        thread.daemon = True
        thread.start()
        
        return jsonify({
            'success': True,
            'message': 'Sync started'
        })
        
    except Exception as e:
        sync_running = False
        return jsonify({
            'success': False,
            'message': str(e)
        })

@app.route('/status', methods=['GET'])
def get_status():
    return jsonify({
        'sync_running': sync_running,
        'timestamp': time.time()
    })

if __name__ == '__main__':
    print("🚀 Starting LeetCode Auto Sync Server...")
    print("📍 Server will run on http://localhost:3000")
    print("🔌 Make sure to install Flask: pip install flask flask-cors")
    app.run(host='localhost', port=3000, debug=False) 