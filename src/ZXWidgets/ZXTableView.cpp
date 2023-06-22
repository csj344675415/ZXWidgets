#include "ZXWidgets.h"
#include <QStandardItemModel>
#include <QHeaderView>
#include <QMenu>

ZXTableView::ZXTableView(QWidget *parent)
	: QTableView(parent)
{
	initTableView();
}

ZXTableView::~ZXTableView()
{

}

void ZXTableView::initTableView()
{
	// 设置排序功能
	this->setSortingEnabled(true);
	// 初始按照哪列数据排序
	this->sortByColumn(0, Qt::AscendingOrder);
	// 是否启用左上角按钮，点击后全选表格
	this->setCornerButtonEnabled(true);
	// 选中时整行高亮
	this->setSelectionBehavior(QAbstractItemView::SelectRows);  //SelectItems   SelectRows
	// 是否显示背景网格线
	this->setShowGrid(true);
	// 是否开启隔行换色
	this->setAlternatingRowColors(false);
	// 水平表头是否可见（列的表头）
	this->horizontalHeader()->setVisible(true);
	// 垂直表头是否可见（行的表头）
	this->verticalHeader()->setVisible(false);
	//隐藏表头排序指示器
	this->horizontalHeader()->setSortIndicatorShown(false);
	// 禁止自动滚动
	this->setAutoScroll(false);
	// 按像素滚动还是一格滚动
	this->setHorizontalScrollMode(QAbstractItemView::ScrollPerPixel);
	//隐藏水平滚动条
	//this->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	//隐藏垂直滚动条
	//this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff); 
	// 最后一列自动占满表格余下的所有部分
	this->horizontalHeader()->setStretchLastSection(true);
	// 设置插入的图标大小
	this->setIconSize(QSize(16, 16));
	// 设置默认行高
	this->verticalHeader()->setDefaultSectionSize(20);
	// 设置单选
	this->setSelectionMode(QAbstractItemView::ExtendedSelection);
	// 设置不可编辑
	this->setEditTriggers(QTableView::NoEditTriggers);
	// 是否使用右键弹出菜单
	this->setContextMenuPolicy(Qt::CustomContextMenu);
	// 右键弹出菜单的信号
	connect(this, &QWidget::customContextMenuRequested, this, &ZXTableView::tableView_customContextMenuRequested);
	//// 点击单元格，能触发信号索引必定有效 
	//connect(this, &QAbstractItemView::clicked, this, &ZXTableView::tableView_clicked);
	//// 单元格被双击时触发，能触发信号索引必定有效 
	//connect(this, &QAbstractItemView::doubleClicked, this, &ZXTableView::tableView_doubleClicked);


	QStandardItemModel *pModel = new QStandardItemModel(this);
	this->setModel(pModel);

	_pMenu = new QMenu(this);
	//_pMenu->addAction("aaa");
	//_pMenu->addAction("bbb");
}
//右键菜单
void ZXTableView::tableView_customContextMenuRequested(const QPoint& pos)
{
	QModelIndex index = this->indexAt(pos);
	if (index.isValid() && _pMenu != nullptr) {
		_pMenu->exec(QCursor::pos());  //弹出菜单
	}
}

void ZXTableView::setMenu(QMenu* pMenu) 
{
	if (this->_pMenu != nullptr) {
		delete _pMenu;
	}
	this->_pMenu = pMenu;
}

////单机单元格
//void ZXTableView::tableView_clicked(const QModelIndex& index)
//{
//	QString str = index.data().toString();
//	QString str2 = index.data(Qt::UserRole + 1).toString(); //获取不显示的用户数据
//}
//
////双击单元格
//void ZXTableView::tableView_doubleClicked(const QModelIndex& index)
//{
//	QString str = index.data().toString();
//
//}




