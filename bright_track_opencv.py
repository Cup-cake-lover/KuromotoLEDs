import numpy as np
import cv2
import matplotlib.pyplot as plt
from PIL import ImageStat,Image


#filename = '/home/hari/Desktop/0.5.mp4'
webcam = cv2.VideoCapture("input.mp4")
bright = []

while True:
    _, imageFrame = webcam.read()
    frame_gs = cv2.cvtColor(imageFrame, cv2.COLOR_BGR2GRAY)
    pil_image = Image.fromarray(frame_gs)

    stat = ImageStat.Stat(pil_image)
    bright.append(stat)


plt.plot(bright)
