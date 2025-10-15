#include <iostream>
#include <vector>
#include <string>
#include <algorithm>  // For std::transform

// Function to analyze logs for breach events
int analyzeLogs(const std::vector<std::string>& logs, std::string& report) {
    int breachCount = 0;
    report = "Data Breach Analysis Report for Singapore Server\n";
    report += "------------------------------------------------\n";
    report += "Summary: This report analyzes server logs for potential data breaches.\n\n";

    for (size_t i = 0; i < logs.size(); ++i) {
        std::string lowerEntry = logs[i];  // Convert to lowercase for case-insensitive search
        std::transform(lowerEntry.begin(), lowerEntry.end(), lowerEntry.begin(), ::tolower);
        
        if (lowerEntry.find("breach") != std::string::npos || lowerEntry.find("unauthorized access") != std::string::npos) {
            breachCount++;
            report += "Event " + std::to_string(i + 1) + ": Potential breach detected - " + logs[i] + "\n";
        }
    }

    report += "\nTotal potential breach events: " + std::to_string(breachCount) + "\n";
    if (breachCount > 0) {
        report += "Recommendation: Investigate immediately and notify authorities.";
    } else {
        report += "No breach events detected. System appears secure.";
    }

    return breachCount;
}

int main() {
    // Sample logs for Singapore server (in a real scenario, read from a file)
    std::vector<std::string> sampleLogs = {
        "2023-10-01 12:00:00 - Normal login from user123",
        "2023-10-01 12:05:00 - Unauthorized access attempt on Singapore server",
        "2023-10-01 12:10:00 - Breach detected in database",
        "2023-10-01 12:15:00 - System restored"
    };

    std::string report;
    int breachCount = analyzeLogs(sampleLogs, report);
    
    std::cout << report << std::endl;
    std::cout << "Analysis complete. Total breaches: " << breachCount << std::endl;

    return 0;
}

// To handle file I/O in a real scenario:
// #include <fstream>
// std::vector<std::string> logs;
// std::ifstream file("server.log");
// std::string line;
// while (std::getline(file, line)) {
//     logs.push_back(line);
// }
// Then call analyzeLogs(logs, report);
