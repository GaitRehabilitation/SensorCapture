/**
* Copyright 2018 GaitRehabilitation
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*     http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*/


#ifndef METAWEARWRAPPERBASE_H
#define METAWEARWRAPPERBASE_H

#include <QObject>

#include <metawear/core/cpp/metawearboard_def.h>
#include "metawear/sensor/accelerometer.h"
#include "metawear/sensor/ambientlight_ltr329.h"
#include "metawear/sensor/gyro_bmi160.h"
#include "metawear/sensor/magnetometer_bmm150.h"
#include "metawear/core/datasignal.h"
#include "common/BluetoothAddress.h"

/**
 * a wrapper object around the core implementation of Metawear
 */
class MetawearWrapperBase : public QObject {
Q_OBJECT
private:
    bool m_isMetawearReady;
    QString m_firmwareVersion;
    QString m_model;
    qint64 m_latestEpoch;

protected:
    MblMwMetaWearBoard *m_metaWearBoard;
    BluetoothAddress m_target;
    void configureHandlers();

public:
    /**
     * initilize metawear wrapper
     * @param address the address of the device to connect to
     */
    explicit MetawearWrapperBase(const BluetoothAddress& address);

    /**
     * connect to the metawear device
     */
    virtual void connectToDevice() = 0;

    /**
     * 
     * @return
     */
    virtual bool isConnected() const = 0;

    void configureAccelerometer(float, float);

    void configureAmbientLight(MblMwAlsLtr329Gain, MblMwAlsLtr329IntegrationTime, MblMwAlsLtr329MeasurementRate);

    void configureGyroscope(MblMwGyroBmi160Range, MblMwGyroBmi160Odr);

    void configureMagnetometer(MblMwMagBmm150Preset);

    void readBatteryStatus();

    void startAccelerationCapture();

    void startAmbientLightCapture();

    void startGyroscopeCapture();

    void startMagnetometerCapture();

    void stopAccelerationCapture();

    void stopAmbientLightCapture();

    void stopGyroscopeCapture();

    void stopMagnetometerCapture();

    void updateEpoch(qint64 epoch);

    const QString& getModel() const;

    qint64 getLatestEpoch();

    const QString& getFirmwareVersion() const;


    const BluetoothAddress& getTarget() const;

signals:

    void connected();

    void disconnected();

    void batteryPercentage(uint8_t);

    void voltage(short);

    void magnetometer(qint64, float, float, float);

    void gyroscope(qint64, float, float, float);

    void acceleration(qint64, float, float, float);

    void metawareInitialized();

    void postMetawearInitialized();

    void metawareFailedToInitialized(int32_t status);

    void latestEpoch(qint64);
};



#endif // METAWEARWRAPPERBASE_H
