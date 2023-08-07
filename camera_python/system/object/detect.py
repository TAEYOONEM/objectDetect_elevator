from ultralytics import YOLO

# model = YOLO("./models/furniture_best.pt")

class Detector :
    def __init__(self, model_file) :
        self.model = YOLO(model_file)

    def modeling(self, frame) :
        self.result = self.model(frame)[0]

    def get_classId(self) :
        try :
            id_list = []
            for box in self.result.boxes:
                class_id = self.result.names[box.cls[0].item()]
                if class_id not in id_list :
                    id_list.append(class_id)
            return id_list
        except Exception as e :
            print(f"{e}")

    def get_boxItem(self) :
        try :
            key_list = []
            for box in self.result.boxes:
                if box.cls[0].item() not in key_list :
                    key_list.append(box.cls[0].item())
            return key_list
        except Exception as e :
            print(f"{e}")
