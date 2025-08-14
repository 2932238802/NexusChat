 #include "midsessionfriendaread.h"


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
    // 设置必要的属性
    // 这样就可以 实现 滑动了
    this->setWidgetResizable(true);

    // 设置垂直划线
    this->verticalScrollBar()->setStyleSheet(style::MIDSCROLLERBAY_HEIGHT);

    // 设置水平方向的
    this->horizontalScrollBar()->setStyleSheet(style::MIDSCROLLERBAY_WIDTH);

    container = new QWidget();
    container->setFixedWidth(310);
    this->setWidget(container);

    // 设置一个布局管理器 方便之后 加入数据
    QVBoxLayout* layout = new QVBoxLayout();
    layout->setContentsMargins(0,0,0,0);
    // layout->setHorizontalSpacing(10);
    layout->setSpacing(0);
    // 向上对齐
    layout->setAlignment(Qt::AlignTop);
    container->setLayout(layout);

    // DEBUG
    MY_LOG_INF("debug ...");
#if DEBUG
    for(int i = 0; i < 30 ; i++)
    {
        QIcon icon(":/resource/image/dog.png");
        this->AddItem(icon,"LosAngelous"+QString::number(i),"你好"+QString::number(i));
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
    const QIcon& avator,
    const QString& name,
    const QString& text
    )
{
    // z增加那妞

    SessionFriendItem* item = new SessionFriendItem(
        this,
        avator,
        name,
        text
        );

    container->layout()->addWidget(item);

}


////////////////////////////////////////////////////////
/// 删除元素 清理元素
////////////////////////////////////////////////////////
/**
 * @brief MidSessionFriendAread::ClearItem
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
            delete item->widget();
        }
    }
    // 开发中不建议使用 无符号类型
}




////////////////////////////////////////////////////////
/// 中间层的 组件之一
////////////////////////////////////////////////////////
// 微信头像选择 就是 微信顶置的那一块的设置
// 布局 用 网格布局
SessionFriendItem::SessionFriendItem(
    QWidget* _owner,
    const QIcon& avator,
    const QString&name,
    const QString&text
    ):owner(_owner)
{
    // 设置样式
    // 70 搞成全局
    this->setFixedHeight(70);
    this->setStyleSheet(style::MIDSCROLLERBAY_FRIENDITEM);

    // 设置布局
    QGridLayout* layout = new QGridLayout();
    layout->setContentsMargins(0,0,0,0);
    layout->setVerticalSpacing(0);
    layout->setHorizontalSpacing(10);
    this->setLayout(layout);


    // 创建头像
    QPushButton* button = new QPushButton();
    button->setFixedSize(50,50);
    button->setIconSize(QSize(50,50)); // 设置图片尺寸
    button->setIcon(avator); // 设置头像
    button->setStyleSheet(style::MIDSCROLLERBAY_AVATOR); // 设置样式
    button->setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed); // 就是不随着 父进行变化

    // 创建名字 Expanding 就是尽可能的扩展
    QLabel* name_label = new QLabel();
    name_label->setText(name);
    name_label->setStyleSheet(style::MID_NAME_LABEL);
    name_label->setFixedHeight(35);
    name_label->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Fixed);

    // 创建消息预览
    QLabel* massage = new QLabel();
    massage->setText(text);
    massage->setFixedHeight(35);
    name_label->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Fixed);


    // 加入到布局管理器里面
    layout->addWidget(button,0,0,2,2); // 头像
    layout->addWidget(name_label,0,2,1,1); // 名字 一行一列
    layout->addWidget(massage,1,2,1,1); // 消息一行一列
}




















