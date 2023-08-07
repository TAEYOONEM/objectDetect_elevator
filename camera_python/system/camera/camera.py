import cv2
        
class Camera :
    def __init__(self, floor) :
        self.floor = floor
        self.cap = cv2.VideoCapture(0)
    
    def get_frame(self) :
        try :
            _, frame = self.cap.read()
            return frame 
        except Exception as e :
            print(f"{e}")


