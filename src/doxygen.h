/******************************************************************************
 *
 * $Id$
 *
 *
 * Copyright (C) 1997-1999 by Dimitri van Heesch.
 *
 * Permission to use, copy, modify, and distribute this software and its
 * documentation under the terms of the GNU General Public License is hereby 
 * granted. No representations are made about the suitability of this software 
 * for any purpose. It is provided "as is" without express or implied warranty.
 * See the GNU General Public License for more details.
 *
 * All output generated with Doxygen is not covered by this license.
 *
 */

#ifndef DOXYGEN_H
#define DOXYGEN_H

#include "groupdef.h"
#include "filedef.h"
#include "classdef.h"
#include "memberdef.h"
#include "classlist.h"
#include "membername.h"
#include "filename.h"
#include "define.h"
#include "namespacedef.h"
#include "formula.h"

struct PageInfo
{
  PageInfo(const char *n,const char *d,const char *t) 
     { name=n; doc=d; title=t; }
  QString name;
  QString doc;
  QString title;
};

class PageList : public QList<PageInfo> 
{
  int compareItems(GCI i1,GCI i2)
  {
    return stricmp(((PageInfo *)i1)->name,((PageInfo *)i2)->name);
  }
};

class BufStr : public QString
{
  public:
    BufStr(int size) : QString(size), offset(0), spareRoom(10240) {}
    void addChar(char c)
    {
      if (offset>=size()) resize(size()+spareRoom);
      data()[offset++]=c;
    }
    void addArray(const char *a,int len)
    {
      if (offset+len>=size()) resize(size()+len+spareRoom);
      memcpy(data()+offset,a,len);
      offset+=len;
    }
    uint curPos() { return offset; }
    void skip(uint s)
    {
      if (offset+s>=size()) resize(size()+s+spareRoom);
      offset+=s;
    }
  private:
    uint offset;
    const int spareRoom; // 10Kb extra room to avoid frequent resizing
};

struct SectionInfo
{
  SectionInfo(const char *n,const char *l,const char *t,bool sub)
    { pageName=n; label=l; title=t; isSubsection=sub; }
  QString pageName;
  QString label; 
  QString title;
  bool isSubsection;
};

typedef QList<QString>     StringList;
typedef QDict<MemberDef>   MemberDict;
typedef QDict<ClassDef>    ClassDict;
typedef QDict<FileDef>     FileDict;
typedef QDict<QString>     StringDict;
typedef QDict<PageInfo>    PageDict;
typedef QDict<SectionInfo> SectionDict;
typedef QDict<GroupDef>    GroupDict;

extern const char * getOverloadDocs();
extern ClassList classList;
extern ClassDict classDict;
extern QStrList tagfileList;
extern PageList exampleList;
extern PageDict exampleDict;
extern PageList pageList;
extern PageDict pageDict;
extern MemberNameList memberNameList;
extern MemberNameList functionNameList;
extern MemberNameDict memberNameDict;
extern MemberNameDict functionNameDict;
extern StringDict substituteDict;
extern FileList fileList;
extern FileDict fileDict;
extern DefineDict defineDict;
extern ClassDef unrelatedClass; 
extern QTextStream tagFile;
extern SectionDict sectionDict;
extern FileNameList inputNameList;
extern FileNameDict includeNameDict;
extern FileNameDict exampleNameDict;
extern FileNameDict inputNameDict;
extern FileList includeFiles; 
extern StringDict typedefDict;
extern GroupList groupList;
extern NamespaceList namespaceList;
extern FormulaList formulaList;
extern FormulaDict formulaDict;
extern FormulaDict formulaNameDict;

extern int annotatedClasses;
extern int hierarchyClasses;
extern int documentedFunctions;
extern int documentedMembers;
extern int documentedDefines;
extern int documentedFiles;
extern int documentedGroups;
extern int documentedNamespaces;

#endif
