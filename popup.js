// Popup script for user interactions
document.addEventListener('DOMContentLoaded', function() {
    const statusDiv = document.getElementById('status');
    const manualSyncBtn = document.getElementById('manualSync');
    const toggleSyncBtn = document.getElementById('toggleSync');
    const lastSyncSpan = document.getElementById('lastSync');

    // Load saved state
    chrome.storage.local.get(['autoSyncEnabled', 'lastSyncTime'], function(result) {
        const autoSyncEnabled = result.autoSyncEnabled !== false; // Default to true
        updateStatus(autoSyncEnabled);
        
        if (result.lastSyncTime) {
            const date = new Date(result.lastSyncTime);
            lastSyncSpan.textContent = date.toLocaleString();
        }
    });

    // Manual sync button
    manualSyncBtn.addEventListener('click', function() {
        chrome.runtime.sendMessage({action: 'manualSync'}, function(response) {
            if (response && response.success) {
                lastSyncSpan.textContent = new Date().toLocaleString();
                chrome.storage.local.set({lastSyncTime: Date.now()});
            }
        });
    });

    // Toggle auto-sync button
    toggleSyncBtn.addEventListener('click', function() {
        chrome.storage.local.get(['autoSyncEnabled'], function(result) {
            const newState = !(result.autoSyncEnabled !== false);
            chrome.storage.local.set({autoSyncEnabled: newState}, function() {
                updateStatus(newState);
            });
        });
    });

    function updateStatus(enabled) {
        if (enabled) {
            statusDiv.className = 'status active';
            statusDiv.textContent = '✅ Auto-sync is active';
            toggleSyncBtn.textContent = 'Disable Auto-Sync';
            toggleSyncBtn.className = 'toggle-btn';
        } else {
            statusDiv.className = 'status inactive';
            statusDiv.textContent = '❌ Auto-sync is disabled';
            toggleSyncBtn.textContent = 'Enable Auto-Sync';
            toggleSyncBtn.className = 'toggle-btn';
        }
    }
}); 