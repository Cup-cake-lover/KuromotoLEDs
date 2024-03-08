from imutils import contours
import numpy as np
import argparse
import imutils
import cv2
import time

import csv
header = ["labels","x_values","y_values"]

with open('test.csv', 'w', encoding='UTF8', newline='') as f:
    csv_writer = csv.DictWriter(f,fieldnames=header)
    csv_writer.writeheader()
with open('test_2.csv', 'w', encoding='UTF8', newline='') as f:
    csv_writer = csv.DictWriter(f,fieldnames=header)
    csv_writer.writeheader()



video = cv2.VideoCapture("leds.mp4")

BINARY_THRESHOLD = 20
CONNECTIVITY = 4
DRAW_CIRCLE_RADIUS = 4

count_1,count_2,count_3,count_4,count_5 = 0,0,0,0,0
blinks1,blinks2,blinks3,blinks4,blinks5 = [],[],[],[],[]
while True:

    _, imageFrame = video.read()
    img = cv2.flip(imageFrame, 1)
    print(img.shape)

    result = imageFrame.copy()
    grayscale = cv2.cvtColor(imageFrame,cv2.COLOR_BGR2GRAY)
    #grayscale = ~grayscale
    blurred = cv2.GaussianBlur(grayscale, (11, 11), 0)
    thresh = cv2.threshold(blurred, 250, 255, cv2.THRESH_BINARY)[1]
    thresh = cv2.erode(thresh, None, iterations=2)
    thresh = cv2.dilate(thresh, None, iterations=4)

    binary_image = cv2.Laplacian(thresh, cv2.CV_8UC1)

    dilated_image = cv2.dilate(binary_image, np.ones((5, 5)))

#  threshold the black/ non-black areas
    _, thresh = cv2.threshold(dilated_image, BINARY_THRESHOLD, 255, cv2.THRESH_BINARY)

#  find connected components
    components = cv2.connectedComponentsWithStats(thresh, CONNECTIVITY, cv2.CV_32S)


    centers = components[3]

    #print(centers)


    for center in centers:
        #print(center)
        #print(int(center[0]), int(center[1]))
        cv2.putText(result, str(components[0]),(int(center[0]), int(center[1])), cv2.FONT_HERSHEY_SIMPLEX, 0.7, (246,255,12), 3)

        cv2.circle(thresh, (int(center[0]), int(center[1])), DRAW_CIRCLE_RADIUS, (255), thickness=-1)

        '''
        if components[0]==3:
            with open('test.csv', 'a') as f:
                csv_writer = csv.DictWriter(f,fieldnames=header)
                #csv_writer.writeheader()
                info = {
                "x_values": 1,
                "y_values": 1
                }

                csv_writer.writerow(info)
        elif components[0]!=3:
            with open('test.csv', 'a') as f:
                csv_writer = csv.DictWriter(f,fieldnames=header)
                #csv_writer.writeheader()
                info = {
                "x_values": 0,
                "y_values": 0
                }

                csv_writer.writerow(info)

        if components[0]==2:
            with open('test_2.csv', 'a') as f:
                csv_writer = csv.DictWriter(f,fieldnames=header)
                #csv_writer.writeheader()
                info = {
                "x_values": 1,
                "y_values": 1
                }

                csv_writer.writerow(info)

        elif components[0]!=2:
            with open('test_2.csv', 'a') as f:
                csv_writer = csv.DictWriter(f,fieldnames=header)
                #csv_writer.writeheader()
                info = {
                "x_values": 0,
                "y_values": 0
                }

                csv_writer.writerow(info)

        '''



        x = center[0]; y = center[1]
        #count_1 = 0 ; count_2 = 0
        if 0 <= x <= 200:
            count_1 = 1
        else:
            count_1 = 0

            with open('test.csv', 'a') as f:
                csv_writer = csv.DictWriter(f,fieldnames=header)
                #csv_writer.writeheader()
                info = {
                "labels":count_1,
                "x_values": center[0],
                "y_values": center[1]
                }
                csv_writer.writerow(info)


        if 200 <= x <= 400:
            count_2 += 1
        else:
            count_2 += 0


            with open('test_2.csv', 'a') as f:
                csv_writer = csv.DictWriter(f,fieldnames=header)
                #csv_writer.writeheader()
                info = {
                "labels":count_2,
                "x_values": center[0],
                "y_values": center[1]
                }
                csv_writer.writerow(info)



    #lines_edges = cv2.addWeighted(imageFrame, 0.8, thresh, 1, 0)
    #cv2.imshow("LED display", thresh)
    #cv2.imshow("t", thresh)
    cv2.imshow('result', result)
    if cv2.waitKey(10) & 0xFF == ord('q'):
        cap.release()
        cv2.destroyAllWindows()

        break
