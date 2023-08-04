from ultralytics import YOLO

model = YOLO("./models/furniture_best.pt")

def modeling(frame) :
    return model(frame)[0]

def get_classId(result) :
    try :
        id_list = []
        for box in result.boxes:
            class_id = result.names[box.cls[0].item()]
            if class_id not in id_list :
                id_list.append(class_id)
        return id_list
    except Exception as e :
        print(f"{e}")

def get_boxItem(result) :
    try :
        key_list = []
        for box in result.boxes:
            if box.cls[0].item() not in key_list :
                key_list.append(box.cls[0].item())
        return key_list
    except Exception as e :
        print(f"{e}")
