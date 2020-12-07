import cv2

# Load the cascade
face_cascade = cv2.CascadeClassifier('haarcascade_frontalface_default.xml')

# Read the input image
img = cv2.imread('sooraj.jpg')

# Convert into grayscale
gray = cv2.cvtColor(img, cv2.COLOR_BGR2RGB)

# Detect faces
faces = face_cascade.detectMultiScale(gray, 1.1, 4)

# Draw rectangle around the faces
for (x, y, w, h) in faces:
    #this is specifically for my photo  a kind of editing u can say
    cv2.circle(img,(x+int(w/2),y+int(h/2)-5),(int(x-1.3*y)),(0,0,255),5)

# Display the output
cv2.imshow('img', img)
cv2.waitKey()
