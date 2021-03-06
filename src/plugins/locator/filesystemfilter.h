/**************************************************************************
**
** This file is part of Qt Creator
**
** Copyright (c) 2009 Nokia Corporation and/or its subsidiary(-ies).
**
** Contact: Nokia Corporation (qt-info@nokia.com)
**
** Commercial Usage
**
** Licensees holding valid Qt Commercial licenses may use this file in
** accordance with the Qt Commercial License Agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and Nokia.
**
** GNU Lesser General Public License Usage
**
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 2.1 as published by the Free Software
** Foundation and appearing in the file LICENSE.LGPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU Lesser General Public License version 2.1 requirements
** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** If you are unsure which license is appropriate for your use, please
** contact the sales department at http://qt.nokia.com/contact.
**
**************************************************************************/

#ifndef FILESYSTEMFILTER_H
#define FILESYSTEMFILTER_H

#include "ilocatorfilter.h"
#include "ui_filesystemfilter.h"

#include <coreplugin/editormanager/editormanager.h>

#include <QtCore/QString>
#include <QtCore/QList>
#include <QtCore/QByteArray>
#include <QtCore/QFutureInterface>

namespace Locator {
namespace Internal {

class LocatorWidget;

class FileSystemFilter : public Locator::ILocatorFilter
{
    Q_OBJECT

public:
    FileSystemFilter(Core::EditorManager *editorManager, LocatorWidget *locatorWidget);
    QString trName() const { return tr("Files in file system"); }
    QString name() const { return "Files in file system"; }
    Locator::ILocatorFilter::Priority priority() const { return Locator::ILocatorFilter::Medium; }
    QList<Locator::FilterEntry> matchesFor(const QString &entry);
    void accept(Locator::FilterEntry selection) const;
    QByteArray saveState() const;
    bool restoreState(const QByteArray &state);
    bool openConfigDialog(QWidget *parent, bool &needsRefresh);
    void refresh(QFutureInterface<void> &) {}

private:
    Core::EditorManager *m_editorManager;
    LocatorWidget *m_locatorWidget;
    bool m_includeHidden;
};

} // namespace Internal
} // namespace Locator

#endif // FILESYSTEMFILTER_H
