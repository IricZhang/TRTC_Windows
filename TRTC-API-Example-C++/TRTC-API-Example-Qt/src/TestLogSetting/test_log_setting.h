/**
 * Logs
 *
 * 1. setLogLevel: set the log output level
 * 2. setConsoleEnabled: enable or disable console log printing
 * 3. setLogCompressEnabled: enable or disable local log compression
 * 4. setLogDirPath: set the path to save logs
 * 5. onLog: callback of log printing
 */

#ifndef TESTLOGSETTING_H
#define TESTLOGSETTING_H

#include "base_dialog.h"
#include "TRTCCloudCallback.h"
#include "ui_TestLogSettingDialog.h"

class TestLogSetting:public BaseDialog,public liteav::ITRTCLogCallback
{
    Q_OBJECT
public:
    explicit TestLogSetting(QWidget *parent = nullptr);
    ~TestLogSetting();

private:
    void setLogLevel();
    void setConsoleEnabled();
    void setLogCompressEnabled();
    void setLogDirPath();
    //============= ITRTCLogCallback start =================//
    void onLog(const char *log, liteav::TRTCLogLevel level, const char *module) override;
    //============= ITRTCLogCallback end ===================//

private slots:

    void on_setLogLevelCb_currentIndexChanged(int index);

    void on_logCompressCb_clicked(bool checked);

    void on_selectLogOutputDirBtn_clicked();

    void on_setConsoleEnabledCb_clicked(bool checked);

private:
    void retranslateUi() override;

    static constexpr const char* LOG_LEVEL_MSG[5] = {
        "Debug   ",
        "Warning ",
        "Critical",
        "Fatal   ",
        "Info    "
    };

    std::unique_ptr<Ui::TestLogSettingDialog> ui_test_log_setting_;

};

#endif // TESTLOGSETTING_H
