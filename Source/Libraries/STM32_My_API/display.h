#ifndef DISPLAY_H_INCLUDED
#define DISPLAY_H_INCLUDED
#include <string.h>
#include "system_foundation.h"
#include "lcd.h"
#include "touch.h"

#ifdef GCC
#include "lcd.c"
#include "touch.c"
#endif

/**======
 * System
 */


/**
 * LCD Display Objects
 */

typedef struct _pt {
	_ushort x, y;
} Point;

#define IS_THE_SAME_POINT(A,B) (( A->x == B->x ) && ( A->y == B->y ) )

typedef struct _btn {
	_nv_uchar *label;
	Point position;
	_ushort width, height;
} Button;


typedef enum {
	RECTANGLE, CIRCLE
} shape;

typedef struct _sbtn {
	Button info;
	shape _shape;
} ShapedButton;

Point pres_ptr = {0,0}; // pres(ent)_p(o)t(inte)r : ��ġ��ũ���� ���� ��ġ
Point conv_ptr = {0,0}; // pres(ent)_p(o)t(inte)r : ��ġ��ũ���� ���� ��ġ
Point previous = {400,400};

bool RetangleBtnOnClick (ShapedButton *b, Point *cpos) {
	bool result = ((cpos->x > b->info.position.x ) && (cpos->x < b->info.position.x+b->info.width ));
	result &= ((cpos->y > b->info.position.y ) && (cpos->y < b->info.position.y+b->info.height ));
	return result;
}

bool point_equals(Point *lhs, Point *rhs){
	return IS_THE_SAME_POINT(lhs,rhs);
}

bool setpos(Point *t, _c_ushort _posx, _c_ushort _posy) {
	bool result = false;
	if (t) {
		t->x = _posx;
		t->y = _posy;
		result = true;
	}
	return result;
}


bool createButton(Button *x, const char *_text, _c_ushort _posx,
		_c_ushort _posy, _c_ushort _height, _c_ushort _width) {

	bool result = false;
	if (x) {
		if (!_text)
			x->label = "";
		else
			x->label = (_nv_uchar*) _text;
		setpos(&(x->position), _posx, _posy);
		x->height = _height;
		x->width = _width;
		result = true;
	}
	return result;
}

bool createRectangleButton(ShapedButton *x, const char *_text, _c_ushort _posx,
		_c_ushort _posy, _c_ushort _height, _c_ushort _width
		) {
	bool result = createButton(&(x->info), _text, _posx, _posy, _height, _width);
	if (result) {
		x->_shape = RECTANGLE;
	}
	return result;
}

bool createCircleButton(ShapedButton *x, const char *_text, _c_ushort _posx,
		_c_ushort _posy, _c_ushort _radius) {
	bool result = createButton(&(x->info), _text, _posx, _posy, _radius, 0);
	if (result) {
		x->_shape = CIRCLE;
	}
	return result;
}

ErrorStatus showRectangleButton(ShapedButton *btn) {
	ErrorStatus result = ERROR;
	_nv_ushort stx, sty, edx, edy,str_x, str_y;
	if (btn) {
		Point *posinfo = &(btn->info.position);
		stx = posinfo->x;
		sty = posinfo->y;
		edx = stx + btn->info.width;
		edy = sty + btn->info.height;
		str_x = ((stx+edx)/2)-(8*(strlen(btn->info.label)/2));
		str_y = ((sty+edy)/2)-8;
		LCD_DrawRectangle(stx, sty, edx, edy);
		LCD_ShowSizedString(str_x,str_y, btn->info.label,16,BLACK, WHITE);
		result = SUCCESS;
	}
	return result;
}

ErrorStatus showCircleButton(ShapedButton *btn) {
	ErrorStatus result = ERROR;
	_nv_ushort cx, cy, r;
	if (btn) {
		Point *posinfo = &(btn->info.position);
		cx = posinfo->x;
		cy = posinfo->y;
		r = btn->info.width;
		LCD_DrawCircle(cx, cy, r);
		LCD_ShowString(cx, cy, btn->info.label,BLACK, WHITE);
		result = SUCCESS;
	}
	return result;
}

ErrorStatus lcdon() {
	if (sysState == ERROR)
		return ERROR;
	LCD_Init();
	Touch_Configuration();
#ifndef DEBUG
	//Touch_Adjust();
#endif
	LCD_Clear(BLACK);
	return SUCCESS;
}

ErrorStatus Touch_Calibtration(){
	ErrorStatus result = ERROR;
	bool check = point_equals(&pres_ptr,&previous);
	if (check){
		Convert_Pos(pres_ptr.x, pres_ptr.y, &conv_ptr.x, &conv_ptr.y);
		result = SUCCESS;
	}
	return result;
}

ErrorStatus Touch_Input() {
	Touch_GetXY(&pres_ptr.x, &pres_ptr.y,1);
	return Touch_Calibtration();
}

#endif

