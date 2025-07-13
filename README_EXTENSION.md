# LeetCode Auto Sync Chrome Extension

This Chrome extension automatically syncs your successful LeetCode submissions to your local repository.

## 🚀 How It Works

1. **Detects Success**: Monitors LeetCode pages for successful submissions
2. **Triggers Sync**: Automatically runs your Python sync script
3. **Real-time**: Works immediately when you solve a problem
4. **No Duplicates**: Only triggers on actual successful submissions

## 📦 Installation

### Step 1: Install Dependencies
```bash
pip install flask flask-cors
```

### Step 2: Start the Local Server
```bash
python server.py
```
Keep this running in the background.

### Step 3: Load the Extension in Chrome

1. Open Chrome and go to `chrome://extensions/`
2. Enable "Developer mode" (toggle in top right)
3. Click "Load unpacked"
4. Select the folder containing these files:
   - `manifest.json`
   - `content.js`
   - `background.js`
   - `popup.html`
   - `popup.js`

### Step 4: Grant Permissions
When prompted, allow the extension to access LeetCode.com

## 🎯 Usage

1. **Automatic**: Just solve LeetCode problems normally - the extension will detect successful submissions and sync automatically
2. **Manual**: Click the extension icon and use "Sync Now" button
3. **Toggle**: Use the extension popup to enable/disable auto-sync

## 🔧 Features

- ✅ Real-time detection of successful submissions
- ✅ Automatic sync to local repository
- ✅ Manual sync option
- ✅ Enable/disable auto-sync
- ✅ Desktop notifications
- ✅ Prevents duplicate syncs
- ✅ Works with all programming languages

## 🛠️ Troubleshooting

### Extension not detecting submissions?
- Make sure you're on LeetCode.com
- Check browser console for any errors
- Verify the local server is running

### Sync not working?
- Check if your `.env` file has correct LeetCode credentials
- Ensure the local server is running on port 3000
- Check the server console for error messages

### Multiple syncs?
- The extension has built-in protection against duplicate triggers
- Wait 5 seconds between submissions

## 📁 Files

- `manifest.json` - Extension configuration
- `content.js` - Detects submissions on LeetCode
- `background.js` - Handles sync triggers
- `popup.html/js` - Extension popup interface
- `server.py` - Local server to trigger Python script

## 🔒 Security

- The extension only runs on LeetCode.com
- No data is sent to external servers
- All sync operations happen locally
- Your LeetCode credentials stay on your machine

## 🎉 That's it!

Now every time you successfully solve a LeetCode problem, it will automatically sync to your local repository! No more manual copying or forgetting to commit solutions. 