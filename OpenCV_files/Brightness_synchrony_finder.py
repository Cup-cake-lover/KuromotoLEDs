import argparse
import numpy as np
import cv2
from PIL import ImageStat, Image
import csv

# Set up argument parsing
parser = argparse.ArgumentParser(description='Process video frames and log brightness.')
parser.add_argument('--b', type=float, required=True, help='Threshold value for brightness')
parser.add_argument('--f', type=str, required=True, help='Input video file')

args = parser.parse_args()
threshold = args.b
input_file = args.f

# Define the CSV header
header = ["k", "b"]

# Create and write the header to the CSV file
with open('test.csv', 'w', encoding='UTF8', newline='') as f:
    csv_writer = csv.DictWriter(f, fieldnames=header)
    csv_writer.writeheader()

# Initialize video capture from the given file
webcam = cv2.VideoCapture(input_file)
k = 0

try:
    # Loop to read frames from the video
    while True:
        # Read a frame from the video
        ret, imageFrame = webcam.read()
        
        # If frame reading was not successful, exit the loop
        if not ret:
            break
        
        # Convert the frame to grayscale
        frame_gs = cv2.cvtColor(imageFrame, cv2.COLOR_BGR2GRAY)
        
        # Convert the grayscale frame to a PIL image
        pil_image = Image.fromarray(frame_gs)
        
        # Get the RMS (root mean square) brightness of the image
        stat = ImageStat.Stat(pil_image)
        s = stat.rms[0]
        
        # Threshold the brightness value using the parsed argument
        if s >= threshold:
            s = 1
        else:
            s = 0

        # Increment frame counter
        k += 1

        # Display the frame
        cv2.imshow("Firefly", imageFrame)

        # Write the frame number and brightness to the CSV file
        with open('test.csv', 'a', newline='') as f:
            csv_writer = csv.DictWriter(f, fieldnames=header)
            info = {"k": k, "b": s}
            csv_writer.writerow(info)

        # Break the loop if 'q' is pressed
        if cv2.waitKey(10) & 0xFF == ord('q'):
            break

except Exception as e:
    # Print the exception if any occurs
    print(f"An error occurred: {e}")

finally:
    # Release the video capture object and close all OpenCV windows
    webcam.release()
    cv2.destroyAllWindows()