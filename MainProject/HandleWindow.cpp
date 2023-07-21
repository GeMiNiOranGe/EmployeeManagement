#include "HandleWindow.h"

const short window::move_to::OFFSET_LEFT = -6;
const short window::move_to::OFFSET_RIGHT = 6;
const short window::move_to::OFFSET_MIDDLE = 3;
const short window::move_to::OFFSET_BOTTOM = 6;

const LONG window::move_to::WORK_AREA_CX = window::get_work_area_size().cx;
const LONG window::move_to::WORK_AREA_CY = window::get_work_area_size().cy;

#pragma region Top of the screen
void window::move_to::top_left() {
	int pos_x = OFFSET_LEFT,
		pos_y = 0;
	move_to_xy(pos_x, pos_y);
}
void window::move_to::top() {
	RECT rect_window;
	HWND hwnd = GetConsoleWindow();
	GetWindowRect(hwnd, &rect_window);
	int pos_x = WORK_AREA_CX / 2 - (rect_window.right - rect_window.left) / 2,
		pos_y = 0;
	move_to_xy(pos_x, pos_y);
}
void window::move_to::top_right() {
	RECT rect_window;
	HWND hwnd = GetConsoleWindow();
	GetWindowRect(hwnd, &rect_window);
	int pos_x = WORK_AREA_CX - (rect_window.right - rect_window.left) + OFFSET_RIGHT,
		pos_y = 0;
	move_to_xy(pos_x, pos_y);
}
#pragma endregion

#pragma region Middle of the screen
void window::move_to::left() {
	RECT rect_window;
	HWND hwnd = GetConsoleWindow();
	GetWindowRect(hwnd, &rect_window);
	int pos_x = OFFSET_LEFT,
		pos_y = WORK_AREA_CY / 2 - (rect_window.bottom - rect_window.top) / 2 + OFFSET_MIDDLE;
	move_to_xy(pos_x, pos_y);
}
void window::move_to::center() {
	RECT rect_window;
	HWND hwnd = GetConsoleWindow();
	GetWindowRect(hwnd, &rect_window);
	int pos_x = WORK_AREA_CX / 2 - (rect_window.right - rect_window.left) / 2,
		pos_y = WORK_AREA_CY / 2 - (rect_window.bottom - rect_window.top) / 2 + OFFSET_MIDDLE;
	move_to_xy(pos_x, pos_y);
}
void window::move_to::right() {
	RECT rect_window;
	HWND hwnd = GetConsoleWindow();
	GetWindowRect(hwnd, &rect_window);
	int pos_x = WORK_AREA_CX - (rect_window.right - rect_window.left) + OFFSET_RIGHT,
		pos_y = WORK_AREA_CY / 2 - (rect_window.bottom - rect_window.top) / 2 + OFFSET_MIDDLE;
	move_to_xy(pos_x, pos_y);
}
#pragma endregion

#pragma region Bottom of the screen
void window::move_to::bottom_left() {
	RECT rect_window;
	HWND hwnd = GetConsoleWindow();
	GetWindowRect(hwnd, &rect_window);
	int pos_x = OFFSET_LEFT,
		pos_y = WORK_AREA_CY - (rect_window.bottom - rect_window.top) + OFFSET_BOTTOM;
	move_to_xy(pos_x, pos_y);
}
void window::move_to::bottom() {
	RECT rect_window;
	HWND hwnd = GetConsoleWindow();
	GetWindowRect(hwnd, &rect_window);
	int pos_x = WORK_AREA_CX / 2 - (rect_window.right - rect_window.left) / 2,
		pos_y = WORK_AREA_CY - (rect_window.bottom - rect_window.top) + OFFSET_BOTTOM;
	move_to_xy(pos_x, pos_y);
}
void window::move_to::bottom_right() {
	RECT rect_window;
	HWND hwnd = GetConsoleWindow();
	GetWindowRect(hwnd, &rect_window);
	int pos_x = WORK_AREA_CX - (rect_window.right - rect_window.left) + OFFSET_RIGHT,
		pos_y = WORK_AREA_CY - (rect_window.bottom - rect_window.top) + OFFSET_BOTTOM;
	move_to_xy(pos_x, pos_y);
}
#pragma endregion

int window::get_taskbar_height() {
	RECT rect;
	HWND taskbar = FindWindow(L"Shell_traywnd", NULL);
	GetWindowRect(taskbar, &rect);
	int height = rect.bottom - rect.top;
	return height;
}

SIZE window::get_work_area_size() {
	RECT rect_work_area;
	SystemParametersInfo(SPI_GETWORKAREA, 0, &rect_work_area, 0);
	SIZE work_area_size = {
		rect_work_area.right - rect_work_area.left,
		rect_work_area.bottom - rect_work_area.top
	};
	return work_area_size;
}

void window::move_to_xy(short pos_x, short pos_y) {
	RECT rect_window;
	HWND hwnd = GetConsoleWindow();
	GetWindowRect(hwnd, &rect_window);
	MoveWindow(hwnd, pos_x, pos_y, rect_window.right - rect_window.left, rect_window.bottom - rect_window.top, TRUE);
}

void window::resize(short width, short height) {
	RECT rect_window;
	HWND hwnd = GetConsoleWindow();
	GetWindowRect(hwnd, &rect_window);
	MoveWindow(hwnd, rect_window.left, rect_window.top, width, height, TRUE);
}