#ifndef REPORT_GENERATOR_H
#define REPORT_GENERATOR_H

#include <QtCore>
#include <QPrinter>
#include <QPdfWriter>

class ReportGenerator {
private:
    QString m_inputFilename;
    QString m_outputFilename;

    QPdfWriter *m_pdfWriter;
    QPainter *m_printer;

public:
    ReportGenerator(const QString &inputFilename, const QString &outputFilename);

    QString create();

    int convertX(qreal x_mm);
    int convertY(qreal y_mm);
    quint32 convertW(qreal width_mm);
    quint32 convertH(qreal height_mm);

    QPoint convert(qreal x_mm, qreal y_mm);
    QRectF convert(const QRectF &r);

    void _setPen(int hex);
    void _setBrush(int hex);
    void _setFont(int size, const QString &fontName = "Helvetica");
    void _fillRect(const QRectF &bounds_mm);
    void _drawRect(const QRectF &bounds_mm);
    void _drawPixmap(const QRectF &bounds_mm, const QString &resourceName);
    void _drawText(const QRectF& boundingBox, const QString &text, int flags = 0);

    void _drawLine(double x1_mm, double y1_mm, double x2_mm, double y2_mm);

    void _drawTable(double x_mm, double y_mm, const QList<double> &colWidths, double cellHeight, const QVector<QStringList> &rows);
    void _drawFrameGraph(const QRectF &bounds_mm, const QList<double> &yLabels, const QList<QDateTime> &xLabels);
    void _drawPlotGraph(const QRectF &bounds_mm, const QList<double> &yValues, const QList<QDateTime> &xValues);
};

#endif // REPORT_GENERATOR_H
