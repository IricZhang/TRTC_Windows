/**
 * Video settings
 *
 * - This module shows how to set encoding parameters for locally captured video, which determine the effects presented to remote users, as well as how to set rendering parameters for local video, which determine the effects of local preview.
 * - Main APIs used:  setVideoEncoderParam(); setLocalRenderParams(). For details, see: https://liteav.sdk.qcloud.com/doc/api/zh-cn/group__ITRTCCloud__cplusplus.html#aa2bc2739031035b40e8f2a76184c20d9
 * -
 * - For the specific method, please refer to:  updateVideoEncoderParams()/updateLocalRenderParams()
 */

#ifndef TESTVIDEOSETTING_H
#define TESTVIDEOSETTING_H

#include <QHash>

#include "base_dialog.h"
#include "ITRTCCloud.h"
#include "ui_TestVideoSettingDialog.h"

class TestVideoSetting:
        public BaseDialog
{
    Q_OBJECT
public:
    explicit TestVideoSetting(QWidget *parent = nullptr);
    ~TestVideoSetting();

private:
    void updateVideoEncoderParams();
    void retranslateUi() override;
    
private slots:
    void on_comboBoxVideoResolution_currentIndexChanged(int index);

    void on_comboBoxResolutionMode_currentIndexChanged(int index);

    void on_comboBoxVideoFps_currentIndexChanged(int index);

    void on_horizontalSliderVideoBitrate_valueChanged(int value);

    void on_checkBoxEnableAdjustRes_stateChanged(int state);

    void on_checkBoxEnableEncSmallVideoStream_stateChanged(int state);

private:
    //UI-related
    void setupVideoResolutionMap();
    void resetUI() override;

private:
    std::unique_ptr<Ui::TestVideoSettingDialog> ui_video_setting_;
    QHash<int, liteav::TRTCVideoResolution> video_resolution_hashmap_;
    liteav::ITRTCCloud *trtccloud_;
};

#endif // TESTVIDEOSETTING_H
