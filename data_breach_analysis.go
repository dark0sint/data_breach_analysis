package main

import (
	"fmt"
	"strings"
)

// Function to analyze logs for breach events
func analyzeLogs(logs []string) (int, string) {
	var breachCount int
	var report strings.Builder

	report.WriteString("Data Breach Analysis Report for Singapore Server\n")
	report.WriteString("------------------------------------------------\n")
	report.WriteString("Summary: This report analyzes server logs for potential data breaches.\n\n")

	for i, logEntry := range logs {
		if strings.Contains(strings.ToLower(logEntry), "breach") || strings.Contains(strings.ToLower(logEntry), "unauthorized access") {
			breachCount++
			report.WriteString(fmt.Sprintf("Event %d: Potential breach detected - %s\n", i+1, logEntry))
		}
	}

	report.WriteString(fmt.Sprintf("\nTotal potential breach events: %d\n", breachCount))
	if breachCount > 0 {
		report.WriteString("Recommendation: Investigate immediately and notify authorities.")
	} else {
		report.WriteString("No breach events detected. System appears secure.")
	}

	return breachCount, report.String()
}

func main() {
	// Sample logs for Singapore server (in a real scenario, read from a file)
	sampleLogs := []string{
		"2023-10-01 12:00:00 - Normal login from user123",
		"2023-10-01 12:05:00 - Unauthorized access attempt on Singapore server",
		"2023-10-01 12:10:00 - Breach detected in database",
		"2023-10-01 12:15:00 - System restored",
	}

	breachCount, report := analyzeLogs(sampleLogs)
	fmt.Println(report)
	fmt.Printf("Analysis complete. Total breaches: %d\n", breachCount)
}
