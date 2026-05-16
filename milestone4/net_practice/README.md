*This project has been created as part of the 42 curriculum by yunguo.*

## Description
NetPractice is a systemic administration and networking project designed to introduce the fundamental concepts of IPv4 routing. The primary goal of this project is to successfully configure small-scale virtual networks. By calculating subnet masks and properly defining routing tables, the objective is to ensure seamless packet delivery between various hosts, routers, switches, and the global Internet, without creating routing loops or overlapping subnets.

## Instructions
### Execution
To run the NetPractice training interface:
1. Extract the provided project archive.
2. Execute the included shell script to launch the environment: `./run.sh`
3. Alternatively, open the `index.html` file directly in any modern web browser to access the graphical simulation.

### Exporting Configurations & Submission Requirements
Once a level is successfully solved (indicated by a green "OK"), you must export your configuration to prove your completion.
* Click the **Export** button located in the interface to download the configuration file for that specific level.
* **Submission Details:** You must submit exactly **10 exported configuration files** (one corresponding to each of the 10 levels). 
* These 10 files must be placed directly at the **root** of your Git repository prior to submission.

## Resources
This project heavily relies on the mastery of the following core networking concepts:
* **TCP/IP Addressing:** Understanding public vs. private IP spaces and identifying network vs. host portions of an address.
* **Subnet Masks:** Utilizing CIDR notation (e.g., `/24`, `/26`, `/30`) to calculate exact block sizes and network boundaries.
* **Default Gateways:** Configuring proper exit points for local networks (using `0.0.0.0/0`).
* **Routers and Switches:** Understanding the difference between collision domains and broadcast domains, and enforcing the rule that routers must bridge distinct networks.
* **OSI Layers:** Specifically focusing on Layer 2 (Data Link - Switches/MAC) and Layer 3 (Network - Routers/IP routing).

### Classic References
* [RFC 791 - Internet Protocol](https://datatracker.ietf.org/doc/html/rfc791)
* Cisco Networking Academy documentation on IPv4 Subnetting.
* IBM Documentation: TCP/IP routing concepts.

### AI Usage Description
AI assistance (specifically, a highly competent, albeit strict, virtual tutor) was utilized exclusively for conceptual clarification and guided debugging during the training phase. The AI was primarily tasked with:
1. Explaining the mathematical formulas behind CIDR block calculations and neighborhood boundaries.
2. Diagnosing routing loop errors and overlapping subnet conflicts caused by incorrect gateway configurations.
3. Reviewing network topologies to reinforce theoretical concepts (e.g., "Longest Prefix Match").

*Note: The AI was not used to blindly generate the final configuration files. All final mathematical calculations and network topologies submitted in the root repository were manually calculated, inputted, and verified by the student.*