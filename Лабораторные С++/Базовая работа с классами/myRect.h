#pragma once
#include <iostream>
class Rect{
	int m_left, m_right, m_top, m_bottom;
	public:
	Rect() {
		m_left = 10;
		m_right = 20;
		m_top = 30;
		m_bottom = 40;
		std::cout << "1\n";
	}
	Rect(const Rect& other) {
		m_left = other.m_left;
		m_right = other.m_right;
		m_top = other.m_top;
		m_bottom = other.m_bottom;
		std::cout << "2\n";
	}
	Rect(int left,int right,int top=0,int bottom=0) {
		if (left >= 0 && right >= 0 && top >= 0 && bottom >= 0) {
			m_left = left;
			m_right = right;
			m_top = top;
			m_bottom = bottom;
		}
		else Rect();
		std::cout << "3\n";
	}
	~Rect() {
		m_left = m_right = m_top = m_bottom = 0;
		std::cout << "Rect destructor\n";
	}
	void InflateRect(int d_left, int d_right, int d_top, int d_bottom) {
		m_left += d_left;
		m_right += d_right;
		m_top += d_top;
		m_bottom += d_bottom;
	}
	void InflateRect(int d_width=1, int d_height=1) {
		m_left += d_width;
		m_right += d_width;
		m_top += d_height;
		m_bottom += d_height;
	}
	void SetAll(int n_left, int n_right, int n_top, int n_bottom) {
		m_left = n_left;
		m_right = n_right;
		m_top = n_top;
		m_bottom = n_bottom;
	}
	int GetLeft() { return m_left; }
	int GetRight() { return m_right; }
	int GetTop() { return m_top; }
	int GetBottom() { return m_bottom; }
	void GetAll(int& dest_left, int& dest_right, int& dest_top, int& dest_bottom) {
		dest_left = m_left;
		dest_right = m_right;
		dest_top = m_top;
		dest_bottom = m_bottom;
	}
	void Normalize() {
		m_left = m_right = (m_left + m_right + 1) / 2; //округляем, т.к. можем потерять дробную часть 
		m_top = m_bottom = (m_top + m_right + 1) / 2; 
	}
};