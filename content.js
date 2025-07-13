// Monitor for successful submissions
let lastSubmissionTime = 0;
let isObserving = false;

// Function to detect successful submission
function detectSuccessfulSubmission() {
    // Only run on LeetCode pages
    if (!window.location.href.includes('leetcode.com')) {
        return false;
    }

    // Look for success indicators on LeetCode
    const successIndicators = [
        // Success message
        '.text-green-s',
        // Accepted status
        '[data-e2e-locator="submission-result"]',
        // Success toast
        '.toast-success',
        // Green checkmark
        '.text-green-500',
        // Success status
        '[data-e2e-locator="submission-status"]',
        // Accepted badge
        '[data-e2e-locator="submission-status-accepted"]'
    ];

    // Check for success indicators
    for (const selector of successIndicators) {
        const elements = document.querySelectorAll(selector);
        for (const element of elements) {
            if (element.textContent.includes('Accepted') || 
                element.textContent.includes('Success') ||
                element.classList.contains('text-green-s') ||
                element.classList.contains('text-green-500')) {
                return true;
            }
        }
    }

    // More specific text detection - only on submission pages
    if (window.location.href.includes('/submissions/')) {
        const successTexts = [
            'Accepted',
            'Success',
            'All test cases passed'
        ];

        for (const text of successTexts) {
            if (document.body.textContent.includes(text)) {
                return true;
            }
        }
    }

    return false;
}

// Function to trigger sync
function triggerSync() {
    const currentTime = Date.now();
    // Prevent multiple triggers within 5 seconds
    if (currentTime - lastSubmissionTime < 5000) {
        console.log('⏱️ Sync already triggered recently, skipping...');
        return;
    }
    lastSubmissionTime = currentTime;

    console.log('🎉 LeetCode submission detected! Triggering sync...');
    
    // Send message to background script with error handling
    try {
        chrome.runtime.sendMessage({
            action: 'triggerSync',
            timestamp: currentTime,
            url: window.location.href
        }, (response) => {
            if (chrome.runtime.lastError) {
                console.error('❌ Error sending message:', chrome.runtime.lastError);
            } else {
                console.log('✅ Sync message sent successfully');
            }
        });
    } catch (error) {
        console.error('❌ Error in triggerSync:', error);
    }
}

// Function to start observing
function startObserving() {
    if (isObserving || !document.body) {
        return;
    }

    try {
        // Monitor for DOM changes
        const observer = new MutationObserver((mutations) => {
            mutations.forEach((mutation) => {
                if (mutation.type === 'childList' || mutation.type === 'attributes') {
                    if (detectSuccessfulSubmission()) {
                        triggerSync();
                    }
                }
            });
        });

        // Start observing
        observer.observe(document.body, {
            childList: true,
            subtree: true,
            attributes: true,
            attributeFilter: ['class', 'style']
        });

        isObserving = true;
        console.log('👀 DOM observer started');
    } catch (error) {
        console.error('❌ Error starting observer:', error);
    }
}

// Initialize when DOM is ready
if (document.readyState === 'loading') {
    document.addEventListener('DOMContentLoaded', () => {
        startObserving();
        // Check on initial load
        setTimeout(() => {
            if (detectSuccessfulSubmission()) {
                triggerSync();
            }
        }, 2000); // Wait a bit for page to fully load
    });
} else {
    startObserving();
    // Check on initial load
    setTimeout(() => {
        if (detectSuccessfulSubmission()) {
            triggerSync();
        }
    }, 2000);
}

// Listen for navigation events (SPA navigation)
let currentUrl = window.location.href;
setInterval(() => {
    if (window.location.href !== currentUrl) {
        currentUrl = window.location.href;
        console.log('🔄 URL changed, checking for submissions...');
        
        setTimeout(() => {
            if (detectSuccessfulSubmission()) {
                triggerSync();
            }
        }, 2000); // Wait for page to load
    }
}, 1000);

console.log('🚀 LeetCode Auto Sync content script loaded!'); 