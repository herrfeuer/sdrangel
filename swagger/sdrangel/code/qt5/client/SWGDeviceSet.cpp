/**
 * SDRangel
 * This is the web REST/JSON API of SDRangel SDR software. SDRangel is an Open Source Qt5/OpenGL 3.0+ (4.3+ in Windows) GUI and server Software Defined Radio and signal analyzer in software. It supports Airspy, BladeRF, HackRF, LimeSDR, PlutoSDR, RTL-SDR, SDRplay RSP1 and FunCube     ---   Limitations and specifcities:       * In SDRangel GUI the first Rx device set cannot be deleted. Conversely the server starts with no device sets and its number of device sets can be reduced to zero by as many calls as necessary to /sdrangel/deviceset with DELETE method.   * Stopping instance i.e. /sdrangel with DELETE method is a server only feature. It allows stopping the instance nicely.   * Preset import and export from/to file is a server only feature.   * Device set focus is a GUI only feature.   * The following channels are not implemented (status 501 is returned): ATV demodulator, Channel Analyzer, Channel Analyzer NG, LoRa demodulator, TCP source   * The content type returned is always application/json except in the following cases:     * An incorrect URL was specified: this document is returned as text/html with a status 400    --- 
 *
 * OpenAPI spec version: 4.0.0
 * Contact: f4exb06@gmail.com
 *
 * NOTE: This class is auto generated by the swagger code generator program.
 * https://github.com/swagger-api/swagger-codegen.git
 * Do not edit the class manually.
 */


#include "SWGDeviceSet.h"

#include "SWGHelpers.h"

#include <QJsonDocument>
#include <QJsonArray>
#include <QObject>
#include <QDebug>

namespace SWGSDRangel {

SWGDeviceSet::SWGDeviceSet(QString* json) {
    init();
    this->fromJson(*json);
}

SWGDeviceSet::SWGDeviceSet() {
    init();
}

SWGDeviceSet::~SWGDeviceSet() {
    this->cleanup();
}

void
SWGDeviceSet::init() {
    sampling_device = new SWGSamplingDevice();
    channelcount = 0;
    channels = new QList<SWGChannel*>();
}

void
SWGDeviceSet::cleanup() {
    
    if(sampling_device != nullptr) {
        delete sampling_device;
    }


    if(channels != nullptr) {
        QList<SWGChannel*>* arr = channels;
        foreach(SWGChannel* o, *arr) {
            delete o;
        }
        delete channels;
    }
}

SWGDeviceSet*
SWGDeviceSet::fromJson(QString &json) {
    QByteArray array (json.toStdString().c_str());
    QJsonDocument doc = QJsonDocument::fromJson(array);
    QJsonObject jsonObject = doc.object();
    this->fromJsonObject(jsonObject);
    return this;
}

void
SWGDeviceSet::fromJsonObject(QJsonObject &pJson) {
    ::SWGSDRangel::setValue(&sampling_device, pJson["samplingDevice"], "SWGSamplingDevice", "SWGSamplingDevice");
    ::SWGSDRangel::setValue(&channelcount, pJson["channelcount"], "qint32", "");
    
    ::SWGSDRangel::setValue(&channels, pJson["channels"], "QList", "SWGChannel");
    
}

QString
SWGDeviceSet::asJson ()
{
    QJsonObject* obj = this->asJsonObject();
    
    QJsonDocument doc(*obj);
    QByteArray bytes = doc.toJson();
    return QString(bytes);
}

QJsonObject*
SWGDeviceSet::asJsonObject() {
    QJsonObject* obj = new QJsonObject();
    
    toJsonValue(QString("samplingDevice"), sampling_device, obj, QString("SWGSamplingDevice"));

    obj->insert("channelcount", QJsonValue(channelcount));

    QJsonArray channelsJsonArray;
    toJsonArray((QList<void*>*)channels, &channelsJsonArray, "channels", "SWGChannel");
    obj->insert("channels", channelsJsonArray);

    return obj;
}

SWGSamplingDevice*
SWGDeviceSet::getSamplingDevice() {
    return sampling_device;
}
void
SWGDeviceSet::setSamplingDevice(SWGSamplingDevice* sampling_device) {
    this->sampling_device = sampling_device;
}

qint32
SWGDeviceSet::getChannelcount() {
    return channelcount;
}
void
SWGDeviceSet::setChannelcount(qint32 channelcount) {
    this->channelcount = channelcount;
}

QList<SWGChannel*>*
SWGDeviceSet::getChannels() {
    return channels;
}
void
SWGDeviceSet::setChannels(QList<SWGChannel*>* channels) {
    this->channels = channels;
}


}

