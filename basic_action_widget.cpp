#include "basic_action_widget.h"
#include <QPainter>
#include <iostream>
#include "action_connection_manager_iface.h"
#include "action_connector_widget.h"
#include <sstream>


basic_action_widget::basic_action_widget(QWidget *parent,std::string n,action_connection_manager_iface* conmgr):
    qt_action(n,parent),basic_action(n,conmgr),from(0),to(0)
{
    std::stringstream ss;
    ss << this->instanceCount;
    std::string str = ss.str();

    this->qlName.setText((n+" "+str).c_str());
}
void basic_action_widget::mouseReleaseEvent(QMouseEvent * event)
{
    std::cout<<"basic_action_widget: mouseReleaseEvent"<<std::endl;

    qt_action::mouseReleaseEvent(event);

    if(this->rect().contains(event->pos())&&!this->isDragging)
    {
        this->getConnectionManager()->connect(this);
    }
}
void basic_action_widget::mousePressEvent(QMouseEvent * event)
{
    std::cout<<"basic_action_widget: mousePressEvent"<<std::endl;
    qt_action::mousePressEvent(event);
}
void basic_action_widget::mouseMoveEvent(QMouseEvent * event)
{

    qt_action::mouseMoveEvent(event);

    if(isDragging)
    {
        if(this->from!=0)
            this->from->onActionMoved();
        if(this->to!=0)
            this->to->onActionMoved();

    }
}
void basic_action_widget::addParameter(std::string name, point_3d_list::parameterTypes type)
{
    parameter_dock_widget* dock = new parameter_dock_widget(this,name);
    this->addParameterDock(dock);
    basic_action::addParameter(dock);
}

