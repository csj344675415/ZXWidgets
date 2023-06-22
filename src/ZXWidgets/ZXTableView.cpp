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
	// ����������
	this->setSortingEnabled(true);
	// ��ʼ����������������
	this->sortByColumn(0, Qt::AscendingOrder);
	// �Ƿ��������Ͻǰ�ť�������ȫѡ���
	this->setCornerButtonEnabled(true);
	// ѡ��ʱ���и���
	this->setSelectionBehavior(QAbstractItemView::SelectRows);  //SelectItems   SelectRows
	// �Ƿ���ʾ����������
	this->setShowGrid(true);
	// �Ƿ������л�ɫ
	this->setAlternatingRowColors(false);
	// ˮƽ��ͷ�Ƿ�ɼ����еı�ͷ��
	this->horizontalHeader()->setVisible(true);
	// ��ֱ��ͷ�Ƿ�ɼ����еı�ͷ��
	this->verticalHeader()->setVisible(false);
	//���ر�ͷ����ָʾ��
	this->horizontalHeader()->setSortIndicatorShown(false);
	// ��ֹ�Զ�����
	this->setAutoScroll(false);
	// �����ع�������һ�����
	this->setHorizontalScrollMode(QAbstractItemView::ScrollPerPixel);
	//����ˮƽ������
	//this->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	//���ش�ֱ������
	//this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff); 
	// ���һ���Զ�ռ��������µ����в���
	this->horizontalHeader()->setStretchLastSection(true);
	// ���ò����ͼ���С
	this->setIconSize(QSize(16, 16));
	// ����Ĭ���и�
	this->verticalHeader()->setDefaultSectionSize(20);
	// ���õ�ѡ
	this->setSelectionMode(QAbstractItemView::ExtendedSelection);
	// ���ò��ɱ༭
	this->setEditTriggers(QTableView::NoEditTriggers);
	// �Ƿ�ʹ���Ҽ������˵�
	this->setContextMenuPolicy(Qt::CustomContextMenu);
	// �Ҽ������˵����ź�
	connect(this, &QWidget::customContextMenuRequested, this, &ZXTableView::tableView_customContextMenuRequested);
	//// �����Ԫ���ܴ����ź������ض���Ч 
	//connect(this, &QAbstractItemView::clicked, this, &ZXTableView::tableView_clicked);
	//// ��Ԫ��˫��ʱ�������ܴ����ź������ض���Ч 
	//connect(this, &QAbstractItemView::doubleClicked, this, &ZXTableView::tableView_doubleClicked);


	QStandardItemModel *pModel = new QStandardItemModel(this);
	this->setModel(pModel);

	_pMenu = new QMenu(this);
	//_pMenu->addAction("aaa");
	//_pMenu->addAction("bbb");
}
//�Ҽ��˵�
void ZXTableView::tableView_customContextMenuRequested(const QPoint& pos)
{
	QModelIndex index = this->indexAt(pos);
	if (index.isValid() && _pMenu != nullptr) {
		_pMenu->exec(QCursor::pos());  //�����˵�
	}
}

void ZXTableView::setMenu(QMenu* pMenu) 
{
	if (this->_pMenu != nullptr) {
		delete _pMenu;
	}
	this->_pMenu = pMenu;
}

////������Ԫ��
//void ZXTableView::tableView_clicked(const QModelIndex& index)
//{
//	QString str = index.data().toString();
//	QString str2 = index.data(Qt::UserRole + 1).toString(); //��ȡ����ʾ���û�����
//}
//
////˫����Ԫ��
//void ZXTableView::tableView_doubleClicked(const QModelIndex& index)
//{
//	QString str = index.data().toString();
//
//}




