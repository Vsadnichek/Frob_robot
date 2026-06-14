uint8 UNKNOWN=0
uint8 GO_STRAIGHT=1
uint8 GO_LEFT=2
uint8 GO_RIGHT=3
uint8 NO_LEFT_TURN=4
uint8 NO_RIGHT_TURN=5
uint8 BUS_STOP=6
uint8 PARKING=7
uint8 DANGER=8

uint8   sign_type
float32 distance
float32 confidence
bool    detected
float32 bbox_center_x
float32 bbox_center_y
float32 bbox_width
float32 bbox_height
