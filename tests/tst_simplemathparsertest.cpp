#include <QString>
#include <QtTest>

#include "simplemathexprparser.h"

class SimpleMathParserTest : public QObject
{
	Q_OBJECT

public:
	SimpleMathParserTest();

private Q_SLOTS:
	void testDoubleComputation();
	void testIntComputation();
};

SimpleMathParserTest::SimpleMathParserTest()
{
}

void SimpleMathParserTest::testDoubleComputation()
{

	QStringList exprs = {"1",
					  "2 + 3.4",
					  "2 + -3.4",
					  "2 - -3.4",
					  "5-2",
					  "7 + 2 - 5",
					  "4.6 * 2 + 13",
					  "4.6 / 2 + 3*3",
					  "4.6 / 0.0 + 3*3",
					  "-4.6 / 0.0 + 3*3",
					  "-4.6 / -0.0 + 3*3",
					  "4.6 / -0.0 + 3*3",
					  "0.0 / 0.0 + 3*3",
					  "2^3 - 4 * 1.5",
					  "2^3.0 - 4 * 1.5",
					  "cos(1)*2",
					  "-cos(1)*2",
					  "cos(1)^3*2",
					  "cos(1)^3.0*2",
					  "cos(1)*2 + sin(3)/2",
					  "cos(acos(-1)+1*3^2.0)*2 + sin(3)/2"};

	QVector<double> expected = {1,
							 2 + 3.4,
							 2 + -3.4,
							 2 - -3.4,
							 5-2,
							 7 + 2 - 5,
							 4.6 * 2 + 13,
							 4.6 / 2 + 3*3,
							 4.6 / 0.0 + 3*3,
							 -4.6 / 0.0 + 3*3,
							 -4.6 / -0.0 + 3*3,
							 4.6 / -0.0 + 3*3,
							 0.0 / 0.0 + 3*3,
							 qPow(2,3) - 4 * 1.5,
							 qPow(2,3.0) - 4 * 1.5,
							 qCos(1)*2,
							 -qCos(1)*2,
							 qPow(qCos(1),3)*2,
							 qPow(qCos(1),3.0)*2,
							 qCos(1)*2 + qSin(3)/2,
							 qCos(qAcos(-1)+1*qPow(3,2.0))*2 + qSin(3)/2};

	for(int i = 0; i < expected.size(); i++){

		double result = utils::parseSimpleMathExpr(exprs[i], QMap<QString,double>());

		bool test = result == expected[i] || qAbs(result - expected[i]) < 1e-12 || (isnan(result) && isnan(expected[i]));

		QVERIFY2(test, QString("Failed when %1 should equal %2 but evaluated to %3.").arg(exprs[i]).arg(expected[i]).arg(result).toStdString().c_str());
	}
}

void SimpleMathParserTest::testIntComputation()
{

	QStringList exprs = {"1",
					  "2 + 3",
					  "2 + -3",
					  "2 - -3",
					  "5-2",
					  "7 + 2 - 5",
					  "4/3",
					  "12/3",
					  "4*3"};

	QVector<int> expected = {1,
							 2 + 3,
							 2 + -3,
							 2 - -3,
							 5-2,
							 7 + 2 - 5,
							 4/3,
							 12/3,
							 4*3};

	for(int i = 0; i < expected.size(); i++){

		int result = utils::parseIntegerMathExpr(exprs[i]);

		QCOMPARE(result, expected[i]);
	}
}

QTEST_APPLESS_MAIN(SimpleMathParserTest)

#include "tst_simplemathparsertest.moc"
