
from serial import Serial 
import time

class Sercom(Serial) :
    def __init__(self,prt,br) :
        super().__init__(port = prt,baudrate = br)
        
    def write_int(self, num) :
        self.write(str(num).encode())
        self.write('\n'.encode())

    def write_end(self) :
        self.write('-1'.encode())
        self.write('\n'.encode())

    def readln(self) :
        return self.readline().decode().rstrip('\r\n')

    def write_up(self, uplist) :
        uplist.sort(reverse=True)
        self.write('u'.encode())
        if self.read_char() == 'o' :
            for i in uplist :
                self.write_id(i+2)
            self.write_end()



