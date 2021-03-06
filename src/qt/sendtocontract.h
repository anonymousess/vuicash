#ifndef SENDTOCONTRACT_H
#define SENDTOCONTRACT_H

#include <QWidget>

class PlatformStyle;
class WalletModel;
class ClientModel;
class ContractTableModel;
class ExecRPCCommand;
class ABIFunctionField;
class ContractABI;
class TabBarInfo;

namespace Ui {
class SendToContract;
}

class SendToContract : public QWidget
{
    Q_OBJECT

public:
    explicit SendToContract(const PlatformStyle *platformStyle, QWidget *parent = 0);
    ~SendToContract();

    void setClientModel(ClientModel *clientModel);
    void setModel(WalletModel *model);
    bool isValidContractAddress();
    bool isValidInterfaceABI();
    bool isDataValid();
    void setContractAddress(const QString &address);

Q_SIGNALS:
    // Fired when a message should be reported to the user
    void message(const QString &title, const QString &message, unsigned int style);

public Q_SLOTS:
    void on_clearAllClicked();
    void on_sendToContractClicked();
    void on_gasInfoChanged(quint64 blockGasLimit, quint64 minGasPrice, quint64 nGasPrice);
    void on_updateSendToContractButton();
    void on_newContractABI();
    void on_functionChanged();
    void on_saveInfoClicked();
    void on_loadInfoClicked();
    void on_pasteAddressClicked();
    void on_contractAddressChanged();

private Q_SLOTS:
    void updateDisplayUnit();

private:
    QString toDataHex(int func, QString& errorMessage);
    bool isFunctionPayable();

private:
    Ui::SendToContract *ui;
    WalletModel* m_model;
    ClientModel* m_clientModel;
    ContractTableModel* m_contractModel;
    ExecRPCCommand* m_execRPCCommand;
    ABIFunctionField* m_ABIFunctionField;
    ContractABI* m_contractABI;
    TabBarInfo* m_tabInfo;
    const PlatformStyle* m_platformStyle;
    int m_results;
    bool bCreateUnsigned = false;
};

#endif // SENDTOCONTRACT_H
