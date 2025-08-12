#ifndef __Line_HH__
#define __Line_HH__

class Line
{
public:
    Line(int x1,int y1,int x2,int y2);
    ~Line();
    void printLine() const;//打印直线的信息
private:
    class LineImpl;
    LineImpl * _pimpl;
};




#endif
