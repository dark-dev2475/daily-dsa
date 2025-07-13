// Background script to handle sync triggers
chrome.runtime.onMessage.addListener((request, sender, sendResponse) => {
    if (request.action === 'triggerSync') {
        console.log('🔄 Background script received sync trigger');
        
        // Show notification
        chrome.notifications.create({
            type: 'basic',
            iconUrl: 'data:image/svg+xml;base64,PHN2ZyB3aWR0aD0iNDgiIGhlaWdodD0iNDgiIHZpZXdCb3g9IjAgMCA0OCA0OCIgZmlsbD0ibm9uZSIgeG1sbnM9Imh0dHA6Ly93d3cudzMub3JnLzIwMDAvc3ZnIj4KPHJlY3Qgd2lkdGg9IjQ4IiBoZWlnaHQ9IjQ4IiByeD0iOCIgZmlsbD0iIzAwN2JmZiIvPgo8cGF0aCBkPSJNMTYgMjRMMjQgMzJMMzIgMjQiIHN0cm9rZT0id2hpdGUiIHN0cm9rZS13aWR0aD0iMyIgc3Ryb2tlLWxpbmVjYXA9InJvdW5kIiBzdHJva2UtbGluZWpvaW49InJvdW5kIi8+Cjwvc3ZnPgo=',
            title: 'LeetCode Auto Sync',
            message: 'Syncing your solution to local repository...'
        });

        // Trigger the local Python script
        triggerLocalSync();
    } else if (request.action === 'manualSync') {
        console.log('🔄 Background script received manual sync request');
        triggerLocalSync().then(result => {
            sendResponse({success: result});
        }).catch(error => {
            sendResponse({success: false, error: error.message});
        });
        return true; // Keep message channel open for async response
    }
});

// Function to trigger local Python script
function triggerLocalSync() {
    return new Promise((resolve, reject) => {
        // We'll use a simple HTTP request to trigger the local script
        // You'll need to set up a simple local server to handle this
        
        fetch('http://localhost:3000/trigger-sync', {
            method: 'POST',
            headers: {
                'Content-Type': 'application/json'
            },
            body: JSON.stringify({
                timestamp: Date.now(),
                action: 'sync'
            })
        })
        .then(response => {
            if (!response.ok) {
                throw new Error(`HTTP ${response.status}: ${response.statusText}`);
            }
            return response.json();
        })
        .then(data => {
            console.log('✅ Sync completed:', data);
            
            // Show success notification
            chrome.notifications.create({
                type: 'basic',
                iconUrl: 'data:image/svg+xml;base64,PHN2ZyB3aWR0aD0iNDgiIGhlaWdodD0iNDgiIHZpZXdCb3g9IjAgMCA0OCA0OCIgZmlsbD0ibm9uZSIgeG1sbnM9Imh0dHA6Ly93d3cudzMub3JnLzIwMDAvc3ZnIj4KPHJlY3Qgd2lkdGg9IjQ4IiBoZWlnaHQ9IjQ4IiByeD0iOCIgZmlsbD0iIzAwN2JmZiIvPgo8cGF0aCBkPSJNMTYgMjRMMjQgMzJMMzIgMjQiIHN0cm9rZT0id2hpdGUiIHN0cm9rZS13aWR0aD0iMyIgc3Ryb2tlLWxpbmVjYXA9InJvdW5kIiBzdHJva2UtbGluZWpvaW49InJvdW5kIi8+Cjwvc3ZnPgo=',
                title: 'LeetCode Auto Sync',
                message: 'Solution synced successfully!'
            });
            
            resolve(true);
        })
        .catch(error => {
            console.error('❌ Sync failed:', error);
            
            // Show error notification
            chrome.notifications.create({
                type: 'basic',
                iconUrl: 'data:image/svg+xml;base64,PHN2ZyB3aWR0aD0iNDgiIGhlaWdodD0iNDgiIHZpZXdCb3g9IjAgMCA0OCA0OCIgZmlsbD0ibm9uZSIgeG1sbnM9Imh0dHA6Ly93d3cudzMub3JnLzIwMDAvc3ZnIj4KPHJlY3Qgd2lkdGg9IjQ4IiBoZWlnaHQ9IjQ4IiByeD0iOCIgZmlsbD0iIzAwN2JmZiIvPgo8cGF0aCBkPSJNMTYgMjRMMjQgMzJMMzIgMjQiIHN0cm9rZT0id2hpdGUiIHN0cm9rZS13aWR0aD0iMyIgc3Ryb2tlLWxpbmVjYXA9InJvdW5kIiBzdHJva2UtbGluZWpvaW49InJvdW5kIi8+Cjwvc3ZnPgo=',
                title: 'LeetCode Auto Sync',
                message: 'Failed to sync solution. Check console for details.'
            });
            
            reject(error);
        });
    });
}

console.log('🚀 LeetCode Auto Sync background script loaded!'); 