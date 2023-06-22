#ifndef _ZXWIDGETS_H_
#define _ZXWIDGETS_H_

#include <QtCore/qglobal.h>

#ifndef BUILD_STATIC
# if defined(ZXWIDGETS_LIB)
#  define ZXWIDGETS_EXPORT Q_DECL_EXPORT
# else
#  define ZXWIDGETS_EXPORT Q_DECL_IMPORT
# endif
#else
# define ZXWIDGETS_EXPORT
#endif


//#include "zxwidgets_global.h"
#include <QTableView>

// 0 ---------------
class ZXWIDGETS_EXPORT ZXWidgets
{
public:
    ZXWidgets();
};

// 1 ---------------
class ZXWIDGETS_EXPORT ZXTableView : public QTableView
{
	Q_OBJECT

public:
	ZXTableView(QWidget* parent = nullptr);
	~ZXTableView();

public slots:
	//void tableView_clicked(const QModelIndex& index);
	//void tableView_doubleClicked(const QModelIndex& index);
	void tableView_customContextMenuRequested(const QPoint& pos);

public:	
	QMenu* getMenu() { return _pMenu; }
	void setMenu(QMenu* pMenu);

private:
	void initTableView();
	QMenu* _pMenu = nullptr;
};



#endif // !_ZXWIDGETS_H_