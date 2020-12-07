import cv2
#for general photo
# Load the cascade
face = cv2.CascadeClassifier('haarcascade_frontalface_default.xml')

# To capture video from webcam. 
c = cv2.VideoCapture(0)
# To use a video file as input 
# cap = cv2.VideoCapture('filename.mp4')

while True:
    
    _, img = cap.read()

   #convert from bgr to rgb 
    gray = cv2.cvtColor(img, cv2.COLOR_BGR2RGB)

    # Detect the faces
    faces = face.detectMultiScale(gray, 1.1, 4)

    # Draw the rectangle around each face
    for (x, y, w, h) in faces:
        cv2.rectangle(img, (x, y), (x+w, y+h), (0,255,0), 2)

    # Display
    cv2.imshow('img', img)

    # Stop if escape key is pressed
    if cv2.waitKey(30) & 0xff:
        break
        
# Release the VideoCapture object
c.release()