#ifndef ACTION_CONNECTION_MANAGER_IFACE_H
#define ACTION_CONNECTION_MANAGER_IFACE_H

#include "action_iface.h"

class basic_action_widget;

class action_connection_manager_iface
{
public:
    virtual void startConnection(basic_action_widget* to) = 0;
    virtual void stopConnection(basic_action_widget* to) = 0;
    virtual void connect(basic_action_widget* to) = 0;
};

#endif // ACTION_CONNECTION_MANAGER_IFACE_H
