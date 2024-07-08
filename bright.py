import numpy as np
import cv2
import matplotlib.pyplot as plt
from PIL import ImageStat,Image
import csv
header = ["k","b"]


with open('test.csv', 'w', encoding='UTF8', newline='') as f:
    csv_writer = csv.DictWriter(f,fieldnames=header)
    csv_writer.writeheader()


#filename = '/home/hari/Desktop/0.5.mp4'
webcam = cv2.VideoCapture("input2.mp4")
bright = []
k = 0
while True:
    try:
        _, imageFrame = webcam.read()
        frame_gs = cv2.cvtColor(imageFrame, cv2.COLOR_BGR2GRAY)
        pil_image = Image.fromarray(frame_gs)



        stat = ImageStat.Stat(pil_image)
        #print(stat.rms[0])
        s = stat.rms[0]
        if s>=65:
            s = 1
        else:
            s = 0
        #bright.append(stat)

        k+=1

        cv2.imshow("Firefly", imageFrame)

        with open('test.csv', 'a') as f:
            csv_writer = csv.DictWriter(f,fieldnames=header)
            #csv_writer.writeheader()
            info = {
            "k":k,
            "b":s
            }

            csv_writer.writerow(info)




        if cv2.waitKey(10) & 0xFF == ord('q'):
            cap.release()
            cv2.destroyAllWindows()

            break

    except:
        pass
