/*
 * Copyright (C) by Klaas Freitag <freitag@owncloud.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; version 2 of the License.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
 * or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License
 * for more details.
 */

#ifndef FILEITEMDIALOG_H
#define FILEITEMDIALOG_H

#include <QDialog>
#include <QDateTime>

#include "mirall/progressdispatcher.h"

#include "ui_fileitemdialog.h"

namespace Mirall {
class SyncResult;

namespace Ui {
  class ItemProgressDialog;
}
class Application;

class ItemProgressDialog : public QDialog
{
    Q_OBJECT
public:
    explicit ItemProgressDialog(Application *app, QWidget *parent = 0);
    ~ItemProgressDialog();

    void setupList();

signals:

public slots:
    void accept();
    void slotProgressInfo( const QString& folder, const Progress::Info& progress );
    void slotProgressErrors( const QString& folder, const Progress::SyncProblem& problem );

protected slots:
    void copyToClipboard();

signals:
    void guiLog(const QString&, const QString&);

private:
    QTreeWidgetItem *createFolderItem(const QString& folder);
    QTreeWidgetItem *findFolderItem( const QString& folder );
    void cleanErrors( const QString& folder );
    void decorateFolderItem( const QString& folder );

    QHash<QString, QTreeWidgetItem*> _folderItems;
    const int ErrorIndicatorRole;
    Ui::ItemProgressDialog *_ui;
    int _problemCounter;
};

}
#endif // FILEITEMDIALOG_H
