/******************************************************************************
 *
 * $Id$
 *
 *
 * Copyright (C) 1997-2001 by Dimitri van Heesch.
 *
 * Permission to use, copy, modify, and distribute this software and its
 * documentation under the terms of the GNU General Public License is hereby 
 * granted. No representations are made about the suitability of this software 
 * for any purpose. It is provided "as is" without express or implied warranty.
 * See the GNU General Public License for more details.
 *
 */

#ifndef _MAINHANDLER_H
#define _MAINHANDLER_H

#include <qlist.h>
#include "basehandler.h"
#include "compoundhandler.h"
#include "doxmlintf.h"

class MainHandler : public IDoxygen, public BaseHandler<MainHandler>
{
  public:
    virtual void startCompound(const QXmlAttributes& attrib);
    MainHandler();
    virtual ~MainHandler();

    QListIterator<ICompound> getCompoundIterator() const
    {
      return m_compounds;
    }
    ICompound *getCompoundById(const QString &id) const
    {
      return m_compoundDict[id];
    }
    virtual ICompound *getCompoundByName(const QString &name) const
    {
      return name.isEmpty() ? 0 : m_compoundNameDict[name]; 
    }
    virtual IMember *getMemberById(const QString &id) const
    {
      return m_memberDict[id];
    }
    virtual QList<IMember> *getMemberByName(const QString &name) const
    {
      return m_memberNameDict[name]; 
    }
    void insertMemberById(const QString &id,IMember *h);
    void insertMemberByName(const QString &name,IMember *h);

    void initialize();

  private:
    QList<ICompound>       m_compounds;
    QDict<ICompound>       m_compoundDict;
    QDict<ICompound>       m_compoundNameDict;
    QDict<IMember>         m_memberDict;
    QDict<QList<IMember> > m_memberNameDict;
};

#endif
