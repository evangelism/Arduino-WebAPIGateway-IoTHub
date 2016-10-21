# Arduino-WebAPIGateway-IoTHub
This sample project demonstrates posting messages from Arduino board to IoT Hub via simple WebAPI Gateway

## ������ IoT Hub � ������

��� ������ ������� � ������ ���� IoT Hub (������ "�������� �����"). ����� �������� ���� ���������� ������ �����������:

![Get Access Key](images/IoTHub_AccessKeys.PNG)

����������� � ���������� [Device Explorer](https://github.com/Azure/azure-iot-sdks/blob/master/tools/DeviceExplorer/doc/how_to_use_device_explorer.md). � ��� �������
������ ����������� � IoT-����:

![Device Explorer 1](images/DeviceExplorer1.PNG)

����� ����� ��������� �� ������� "Management" � �������� ����� ����������. ����� ������ ������� ������� �� ������ � ����������� � �������� "Copy Connection String".

![Device Explorer 2](images/DeviceExplorer2.PNG)

## ������������� � ������ WebAPI Gateway

� �������� ���� WebAPI Gateway ���������� ������ ���������� ������� ����������� � IoT Hub (���������� � ���������� ������)
� ���� `Web.Config`:

```
<configuration>
  <appSettings>
    <add key="HubConnectionString" value="..."/>
```

����� ����� ����� ���������� Web API Gateway � ������ ��� Azure Web App. ���� ���������� ����� ��������� �� ������
`http://webapigateway.azurewebsites.net/`, �� ��������� ������:
`http://webapigateway.azurewebsites.net/gw/hub/secret?temp=10&id=dev1` ������� � �������� � IoT Hub ������ JSON-���������:
`{"temp":"10","id":"dev1"}`.

����� `secret` - ��� ��������� ��������� ������������������ ��������, ���������� ������� ����������� � �����
`Controllers/HubController.cs`. � ������ ������ �� �������� �������� �� ���������� ���� � ������ �������, �� ��� ����
�� ��������.

## ���������� ��� Arduino

����� ����� ���������� ������ ������ ��� Arduino, ������� �������� ������ � ����������� ��� � 10 �����, �� ���� ������� ����
���������� - ���������� ������� � ����������� � 1 ������.
