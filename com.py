
from serial import Serial 
import time

class Sercom(Serial) :
    def __init__(self,prt,br) :
        super().__init__(port = prt,baudrate = br)

    def send_id(self, id) :
        self.write(id.encode())

    def send_end(self) :
        pass

    def read_char(self) :
        pass

if __name__ == "__main__" :
    sc = Sercom("COM3", 9600)
    while True :
        sc.send_id("1")
        time.sleep(500)