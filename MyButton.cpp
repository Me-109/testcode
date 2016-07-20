#include "MyButton.h"

CMyButton::CMyButton(QWidget *parent)  
	: QPushButton(parent)  
{  
	//Ϊ����ͼ�꿴������Ȼһ�������������������  
	setDown(false);  
	setFocusPolicy(Qt::NoFocus);  
	SetButtonIcons();
}  

CMyButton::~CMyButton()  
{  

}  

//���ء����롱�͡��뿪���¼�������ʱ�л�Ϊ��һ��ͼ�꣬�뿪ʱ��ԭ  
void CMyButton::enterEvent(QEvent *event)  
{  
	if( isEnabled() && !m_FocusIcon.isNull() )  
		//setIcon(m_FocusIcon);  
	image.load(":/new/prefix1/Resources/buttonTwo.png");
}  

void CMyButton::leaveEvent(QEvent *event)  
{  
	if( isEnabled() )  
		//setIcon(m_NormalIcon);  
	image.load(":/new/prefix1/Resources/buttonFour.png");
}  

//��������¼�  
void CMyButton::mousePressEvent(QMouseEvent *event)  
{  
	if( isEnabled() && !m_PressedIcon.isNull() ) 
		image.load(":/new/prefix1/Resources/buttonOne.png");
		//setIcon(m_PressedIcon);  
	QPushButton::mousePressEvent(event);  
}  

void CMyButton::mouseReleaseEvent(QMouseEvent *event)  
{  
	if( isEnabled() && m_FocusIcon.isNull() )  
		setIcon(m_FocusIcon);  
	QPushButton::mouseReleaseEvent(event);  
}  

void CMyButton::SetButtonIcons()  
{  
	m_NormalIcon = QIcon(":/new/prefix1/Resources/buttonOne.png");  
	m_FocusIcon = QIcon(":/new/prefix1/Resources/buttonTwo.png");  
	m_PressedIcon = QIcon(":/new/prefix1/Resources/buttonFour.png");  
	//setIcon(m_NormalIcon);  
	image.load(":/new/prefix1/Resources/buttonThree.png");
}  
 
void CMyButton::paintEvent(QPaintEvent *event)
{
	
	//QPainter painter(&image); //����painter
	QPainter draw(this);        //����QPainter����ָ�봫����豸

	QRect rect(0,0,this->width(),this->height());  //������ͼ����

	draw.drawImage(rect,image);                    //��ͼ��drawImage�кܶ����غ������ɸ����Լ�����Ҫ������Ӧ����    
	//painter.setRenderHint(QPainter::Antialiasing, true); //�������Ч��

	//����painterpath
	/*QPainterPath path;
	path.moveTo(0, 0);
	path.lineTo(20, 0);
	path.lineTo(20/2, 20);
	path.lineTo(0, 0);*/

	//path->setFillRule(Qt::WindingFill);
	//�����޻��ʣ�����߿����һ������
	//painter.setPen(Qt::NoPen);
	//���û�ˢ
	//painter.setBrush(QBrush(QColor(36,169,225), Qt::SolidPattern));
	//���Ʊ���
	//painter.drawPath(path);
	//painter.drawEllipse(10,3,20,20);

	//painter.drawImage();
	//event->accept();//�������ഫ����Ϣ
}