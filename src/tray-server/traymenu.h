/******************************************************************************

   Copyright (C) 2007 M.K.A. <wyrmchild@users.sourceforge.net>

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software Foundation,
   Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.

******************************************************************************/

#ifndef TrayMenu_INCLUDED
#define TrayMenu_INCLUDED

#include <QWidget>
#include <QSystemTrayIcon>

#include "../server/server.h"
#include "srvthread.h"

class StatusDialog;
class ConfigDialog;

class QAction;
class QMenu;

class TrayMenu
	: public QWidget
{
	Q_OBJECT
	
public:
	TrayMenu();
	
public slots:
	//void configClosed();
	//void statusClosed();
	
private slots:
	//! Set tray icon
	void setIcon(int index);
	//! Detect double-clicking of tray icon and toggle status window with it
	void iconActivated(QSystemTrayIcon::ActivationReason reason);
	//! Show balloon message
	void showMessage(const QString& title, const QString& message, QSystemTrayIcon::MessageIcon icon=QSystemTrayIcon::NoIcon, uint delay=5000);
	
	//! Menu 'start' action
	void startSlot();
	//! Menu 'stop' action
	void stopSlot();
	//! Menu 'config' action
	void configSlot();
	//! Menu 'status' action
	void statusSlot();
	
private:
	
	void createActions();
	
	void createTrayIcon();
	
	
	void toggleStartStop(bool started);
	
	ServerThread *srvthread;
	
	QString title;
	
	Server *srv;
	
	ConfigDialog *config;
	StatusDialog *status;
	
	QAction *quitAction;
	QAction *separator;
	QAction *startAction;
	QAction *stopAction;
	QAction *configureAction;
	QAction *statusAction;
	
	QSystemTrayIcon *trayIcon;
	QMenu *menu;
};

#endif // TrayMenu_INCLUDED