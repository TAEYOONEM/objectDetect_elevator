from detect import *
import cv2

cap = cv2.VideoCapture(0)

def run(): 
    while True :
        ret, frame  =cap.read()
        if not ret :
            break

        frame = cv2.resize(frame,(1020,600))
        result = modeling(frame)

        key_list = get_boxItem(result)

        cv2.imshow('Object Count',result.plot())
        if cv2.waitKey(25) & 0xFF == ord("q") :
            cv2.destroyAllWindows()
            break
        

if __name__ == "__main__" :
    run()