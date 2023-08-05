import cv2

# sc = Sercom("COM3", 9600)

# def test() :
#     frame = cv2.imread("samples/test5.jpg")
#     frame = cv2.resize(frame,(1020,600))
#     result = modeling(frame)
#     key_list = get_boxItem(result)
#     if len(key_list) != 0 :
#         sc.write_up(key_list)

# def run(): 
#     while True :
#         ret, frame  =cap.read()
#         if not ret :
#             break

#         frame = cv2.resize(frame,(1020,600))
#         result = modeling(frame)

#         # key_list = get_boxItem(result)
#         # # print(key_list)
#         # if len(key_list) != 0 :
#         #     rcv = sc.read_char()
#         #     if(rcv == 'o') :
#         #         sc.write_up(key_list)
        
#         cv2.imshow('Object Count',result.plot())
#         if cv2.waitKey(25) & 0xFF == ord("q") :
#             cv2.destroyAllWindows()
#             break
        
class Camera() :
    def __init__(self, floor) :
        self.floor = floor
        self.cap = cv2.VideoCapture(0)
    
    def get_frame(self) :
        try :
            _, frame = self.cap.read()
            return frame 
        except Exception as e :
            print(f"{e}")

    def show_frame(self, frame) :
        try :
            cv2.imshow(f'{self.floor} CAMERA', frame)
        except Exception as e :
            print(f"{e}")
    