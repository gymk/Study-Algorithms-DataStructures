
#ifndef __CLASS_TIME_MEASURE_HPP__
#define __CLASS_TIME_MEASURE_HPP__

#define ENABLE_FUNCTION_TIME_MEASUREMENT

#include <iostream>
#include <iomanip>
#include <chrono>

/* To measure the functoin time taken */
#define DEF_TIME_MEASURE_FUNC(__USER_STR_OR_UIN32__)    CTimeMeasure	timeMeasure(__FUNCTION__, __LINE__, __USER_STR_OR_UIN32__);

/* To print function time taken along with its int value */
#define DEF_TIME_MEASURE_VAR(__USER_STR_OR_UIN32__)     CTimeMeasure	timeMeasure(__FUNCTION__, __LINE__, __USER_STR_OR_UIN32__);

#ifdef ENABLE_FUNCTION_TIME_MEASUREMENT
#define CTIMEMEASURE_TIME_LOG(_X_)      DEF_TIME_MEASURE_VAR(_X_);

#define MESAURE_FUNC_EXECUTION_TIME     CTIMEMEASURE_TIME_LOG(__FUNCTION__)
#else
#define MESAURE_FUNC_EXECUTION_TIME     /* No Operation */
#endif /* !ENABLE_FUNCTION_SCOPE_LOGGING */

/*
*
*/

class CTimeMeasure
{
public:
	CTimeMeasure(const char * pi8FuncName, unsigned int ui32LineNo, const char * pi8UserStr)
	{
		m_pi8FuncName = pi8FuncName;
		m_ui32LineNo = ui32LineNo;
		m_pi8UserStr = pi8UserStr;
		markStartTime();
	};
	CTimeMeasure(const char * pi8FuncName, unsigned int ui32LineNo, unsigned int ui32UserUint32)
	{
		m_pi8FuncName = pi8FuncName;
		m_ui32LineNo = ui32LineNo;
		m_pi8UserStr = nullptr;
		m_ui32UserUint32 = ui32UserUint32;
		markStartTime();
	};
	~CTimeMeasure()
	{
		markEndTime();

		if (m_pi8UserStr != nullptr)
		{
			printTimeTaken();
		}
		else
		{
			printTimeTaken(m_ui32UserUint32);
		}
	};

public:
	void markStartTime(void)
	{
		start = std::chrono::steady_clock::now();
	};

	void markEndTime(void)
	{
		end = std::chrono::steady_clock::now();
	};

	void printTimeTaken(void)
	{
		printf("(%s:%s took %lu microseconds)\n", m_pi8FuncName, m_pi8UserStr, (unsigned long int)(std::chrono::duration_cast<std::chrono::microseconds>(end - start).count()));
		//std::cout << "(" << m_pi8FuncName << "_" << m_pi8UserStr << " took " << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() << " microseconds)\n";
	}

	void printTimeTaken(unsigned int ui32Data)
	{
		printf("(%s:0x%08X took %lu microseconds)\n", m_pi8FuncName, ui32Data, (unsigned long int)(std::chrono::duration_cast<std::chrono::microseconds>(end - start).count()));
		//std::cout << "(" << m_pi8FuncName << "_0x" << std::setfill('0') << std::setw(8) << std::hex  << ui32Data << std::dec
		//          << " took " << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() << " microseconds)\n";
	}

private:
	std::chrono::steady_clock::time_point start;
	std::chrono::steady_clock::time_point end;

	const char * m_pi8UserStr;
	unsigned int m_ui32UserUint32;

	const char * m_pi8ModuleName;
	const char * m_pi8FuncName;
	unsigned int m_ui32LineNo;
};

#endif /* !__CLASS_TIME_MEASURE_HPP__ */

