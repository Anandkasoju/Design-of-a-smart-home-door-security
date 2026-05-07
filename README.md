ESP32-CAM Smart Door Access System 

📷 IoT-Based Home Security with Real-Time Face Detection & Smart Bell Technology 

This repository contains the implementation and documentation for a Smart Home Door Access System powered by the ESP32-CAM. This project enhances traditional home security by integrating face detection algorithms, a smart bell interface, and wireless image transmission, allowing homeowners to monitor visitors and control access remotely via a mobile device or web server. 


📋 Table of Contents 

     Project Overview 
     Key Features 
     Hardware Requirements 
     System Architecture 
     How It Works 
     Results & Implementation 
     Citation 
     

🌟 Project Overview 

Traditional mechanical locks and basic doorbells lack active protection capabilities. This project addresses these limitations by building a compact, low-cost security node using the ESP32-CAM.  

The system captures images when a visitor approaches or rings the bell, processes them locally to detect faces, and transmits the data wirelessly to the homeowner. This setup ensures real-time monitoring and intelligent entry-point control without requiring expensive hardware. 
✨ Key Features 

     Real-Time Face Detection: Utilizes the ESP32-CAM to detect human faces instantly at the entrance.
     Smart Bell Integration: Triggered by a physical button press or motion detection.
     Wireless Transmission: Sends snapshots and alerts to a remote phone or cloud storage via Wi-Fi.
     Low Power & Compact: Designed to fit small spaces with optimized power usage for battery operation.
     Context-Aware Logic: Distinguishes between movement and actual human faces to prevent false alarms.
     Remote Monitoring: Allows homeowners to see who is at the door from anywhere in the world.
     

🛠 Hardware Requirements 

To build this project, you will need the following components: 
Component
 
	
Description
 
 
ESP32-CAM	Main processing unit with integrated camera and Wi-Fi. 
Power Supply Unit (5V)	Provides stable voltage to the ESP32 and peripherals. 
Push Button	Acts as the Smart Bell trigger. 
Buzzer/LED	Local audio/visual indicators for alerts. 
Relay Module / Servo Motor	For simulating or controlling the door lock mechanism. 
Jumper Wires & Breadboard	For connections. 
   
🏗 System Architecture 

The system is built around the ESP32-CAM, which acts as the central brain. 

    Input Layer: The Doorbell button or motion sensor triggers the system. 
    Processing Layer: The ESP32-CAM captures an image and runs a face detection model (e.g., Haar Cascade or similar lightweight models suitable for embedded systems). 
    Output Layer:
         If a face is detected: Image is sent over Wi-Fi; the door may unlock if authorized.
         If no face is detected (or unauthorized): An alert is triggered, and the image is logged for the owner.
          

Workflow Logic: 
  
 <img width="1100" height="142" alt="image" src="https://github.com/user-attachments/assets/2dd345da-f0ec-4d2d-87ed-730b7825cc27" />

  
⚙ How It Works 
1. System Initialization 

Upon powering the ESP32-CAM, the system initializes: 

     Camera configuration.
     GPIO pins (Buzzer, Relay, Bell).
     Wi-Fi connection to the local network (iotserver).
     

2. Visitor Detection 

When a visitor presses the doorbell: 

     The ESP32-CAM receives the trigger signal.
     It immediately captures a photo frame.
     

3. Image Processing 

The system processes the captured image: 

     Converts frames to grayscale or adjusts size for the model.
     Runs the face detection inference to verify the presence of a human face.
     

4. Decision & Notification 

     If Face Detected: The image is transmitted to the IP address (configured via the Network Scanner app). The homeowner receives a notification.
     Access Control: If the face matches an enrolled user, the relay triggers the door lock. If unknown, an alert sounds.
     

5. Reset 

After the action, the system returns to standby mode, ready for the next visitor. 
📸 Results & Implementation 

The system has been successfully tested with the following outcomes: 

    Network Connection: The ESP32-CAM successfully connects to the designated Wi-Fi network. 
    IP Streaming: Users can access the live feed and captured snapshots by entering the ESP32's IP address in a browser or "Network Scanner" app. 
    Face Enrollment: The system supports enrolling faces (as seen in the interface) for authorized access. 
    Alert Latency: Notifications and image transmission occur in real-time with minimal delay. 




📄 Citation 

This project is based on the research published in the International Journal of Advanced Research in Science, Communication and Technology (IJARSCT). 

Title: Face Detection and Smart Bell Technology are Features of this ESP32-CAM-Powered Smart Home Door Access System 

Authors:  

     Y. Harshini¹
     K. Anand²
     A. Akshitha³
     Dr. J. Narasimharao⁴
     

Affiliation: Department of Computer Science & Engineering, CMR Technical Campus, Hyderabad, India. 

Publication Details: 

     Volume 6, Issue 8, March 2026
     DOI: 10.48175/IJARSCT-32166
     ISSN: 2581-9429
     

📝 License 

This project is provided for educational and research purposes. Please refer to the original journal IJARSCT  for copyright details regarding the paper. 
🔗 References 

[1] Salsabila, N., et al. "Home door security system with face detection and a smart bell using ESP32-CAM." 2025 6th International Conference on Mobile Computing and Sustainable Informatics. 

[2] Zakaria, R., et al. "Doorbell monitoring system using ESP32-CAM based on Internet of Things (IoT)." Journal of Industrial Automation and Electrical Engineering, 2024. 

[3] Syafutra, H., et al. "Implementasi sistem keamanan pintu otomatis berbasis face recognition di Proactive Robotic: Integrasi ESP32-Cam dan Telegram." Jurnal Riset Fisika Indonesia, 2024. 
