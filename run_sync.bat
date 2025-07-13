@echo off
cd /d "C:\Users\gagan\daily-dsa"
echo Starting LeetCode sync at %date% %time%
python sync_leetcode.py
echo Finished at %date% %time%
pause 