# data_breach_analysis.py
# This script analyzes server logs for potential data breaches on the Singapore server.

def analyze_logs(logs):
    breach_count = 0
    report = "Data Breach Analysis Report for Singapore Server\n"
    report += "------------------------------------------------\n"
    report += "Summary: This report analyzes server logs for potential data breaches.\n\n"
    
    for i, log_entry in enumerate(logs, start=1):
        if "breach" in log_entry.lower() or "unauthorized access" in log_entry.lower():
            breach_count += 1
            report += f"Event {i}: Potential breach detected - {log_entry}\n"
    
    report += f"\nTotal potential breach events: {breach_count}\n"
    if breach_count > 0:
        report += "Recommendation: Investigate immediately and notify authorities."
    else:
        report += "No breach events detected. System appears secure."
    
    return breach_count, report

# Sample logs for Singapore server (in a real scenario, read from a file like 'server.log')
sample_logs = [
    "2023-10-01 12:00:00 - Normal login from user123",
    "2023-10-01 12:05:00 - Unauthorized access attempt on Singapore server",
    "2023-10-01 12:10:00 - Breach detected in database",
    "2023-10-01 12:15:00 - System restored"
]

breach_count, report = analyze_logs(sample_logs)
print(report)
print(f"Analysis complete. Total breaches: {breach_count}")

# To make this more robust, you could add file I/O:
# import os
# if os.path.exists('server.log'):
#     with open('server.log', 'r') as file:
#         logs = file.readlines()
#         breach_count, report = analyze_logs(logs)
#         print(report)
