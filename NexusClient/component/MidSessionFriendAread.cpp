 #include "MidSessionFriendAread.h"

////////////////////////////////////////////////////////
/// 构造函数
////////////////////////////////////////////////////////
/**
 * @brief MidSessionFriendAread::MidSessionFriendAread
 * @param parent
 */
MidSessionFriendAread::MidSessionFriendAread(QWidget *parent)
    : QScrollArea{parent}
{
    // 参数设置
    current = nullptr;

    // 设置必要的属性
    // 这样就可以 实现 滑动了
    // 设置垂直划线
    // 设置水平方向的
    this->setWidgetResizable(true);
    this->verticalScrollBar()->setStyleSheet(style::MIDSCROLLERBAY_HEIGHT);
    this->horizontalScrollBar()->setStyleSheet(style::MIDSCROLLERBAY_WIDTH); // 这个是为了隐藏的
    container = new QWidget();
    container->setFixedWidth(310);
    this->setWidget(container);

    // 设置一个布局管理器 方便之后 加入数据
    // 向上对齐
    QVBoxLayout* layout = new QVBoxLayout();
    layout->setContentsMargins(0,0,0,0);
    layout->setSpacing(0);
    layout->setAlignment(Qt::AlignTop);
    container->setLayout(layout);

    // DEBUG
    MY_LOG_INF("debug ...");
#if DEBUG
    for(int i = 0; i < 5 ; i++)
    {
        MY_LOG_INF("add item ",i);
        QIcon icon(":/resource/image/dog.png");
        this->AddItem(MidType::SESSION,QString::number(i),icon,"LosAngelous"+QString::number(i),"你好"+QString::number(i));
    }
#endif
}

/////////////////////////////////////////////////////////
/// 官方文档 设置 可以让子类 使用自己的 QSS
/////////////////////////////////////////////////////////
void MidSessionFriendAread::paintEvent(QPaintEvent* event)
{
    QStyleOption opt;
    opt.initFrom(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget,&opt,&p,this);
}

////////////////////////////////////////////////////////
/// 增加元素的函数
////////////////////////////////////////////////////////
void MidSessionFriendAread::AddItem(
    MidType type,
    const QString&id,
    const QIcon& avator,
    const QString& name,
    const QString& text
    )
{
    // z增加那妞
    Baseitem * item = nullptr;


    if(type == MidType::APPLY)
    {
        item = new ApplyLists(
            this,
            id,
            avator,
            name
            );
        MY_LOG_INF("ApplyLists add!");
    }
    else if(type == MidType::FRIEND)
    {
        item = new FriendsLists(
            this,
            id,
            avator,
            name,
            text
            );

        MY_LOG_INF("FriendsLists add!");
    }
    else{

        item = new SessionLists(
            this,
            id,
            avator,
            name,
            text
            );
        MY_LOG_INF("SessionLists add!");
    }

    auto flag = connect(item,&Baseitem::Clicked,this,&MidSessionFriendAread::OnSessionChildClick);
    if(!flag)
    {
        MY_LOG_ERROR("connect error ...");
    }
    else
    {
        MY_LOG_SUC("connected!");
    }

    container->layout()->addWidget(item);
}

////////////////////////////////////////////////////////
/// 删除元素 清理元素
////////////////////////////////////////////////////////
/**
 * @brief MidSessionFriendAread::
 * 1. 清空所有的元素
 */
void MidSessionFriendAread::ClearItem(){

    QLayout* layout = container->layout();
    // 一遍遍历 一遍删除 是危险操作
    // 我们可以都从第一个元素进行删除
    // 或者从后往前删除
    // 注意这里不能使用 size_t 因为 size_t 恒大于等于0 恒成立
    for(int i = layout->count()-1; i >=0 ;i--)
    {
        QLayoutItem* item = layout->takeAt(i);
        if(item->widget())
        {
            auto widget = item->widget();
            widget->deleteLater();
        }
    }
    // 开发中不建议使用 无符号类型
}

void MidSessionFriendAread::OnSessionChildClick(Baseitem* item)
{
    MY_LOG_INF("son component clicked...");
    if(current && current!= item)
    {
        current->SetSatus(false);
    }

    if (item) {
        item->SetSatus(true);
        item->Actived();
        current = item;
    }
}

