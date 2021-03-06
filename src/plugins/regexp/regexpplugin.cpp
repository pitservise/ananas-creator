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

#include "regexpplugin.h"

#include "regexpwindow.h"
#include "settings.h"

#include <coreplugin/baseview.h>
#include <coreplugin/icore.h>
#include <coreplugin/uniqueidmanager.h>

#include <QtCore/QtPlugin>

using namespace RegExp::Internal;

RegExpPlugin::RegExpPlugin()
{
}

RegExpPlugin::~RegExpPlugin()
{
    if (m_regexpWindow)
        m_regexpWindow->settings().toQSettings(Core::ICore::instance()->settings());
}

void RegExpPlugin::extensionsInitialized()
{
}

bool RegExpPlugin::initialize(const QStringList &arguments, QString *errorMessage)
{
    Q_UNUSED(arguments)
    Q_UNUSED(errorMessage)
    Core::ICore *core = Core::ICore::instance();
    m_regexpWindow = new RegExpWindow;
    Settings settings;
    settings.fromQSettings(core->settings());
    m_regexpWindow->setSettings(settings);
    const int plugId = core->uniqueIDManager()->uniqueIdentifier(QLatin1String("RegExpPlugin"));
    addAutoReleasedObject(new Core::BaseView("TextEditor.RegExpWindow",
                                             m_regexpWindow,
                                             QList<int>() << plugId,
                                             Qt::RightDockWidgetArea));
    return true;
}

Q_EXPORT_PLUGIN(RegExpPlugin)
