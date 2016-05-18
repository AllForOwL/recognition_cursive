#pragma once



ref class Neuron
{
	private:
		double m_dLocalField;
		double m_dThreshold;
		double m_dFunctionSignal;
		double m_dFunctionActivate;
		int    m_iCountInputs;
		int    m_iLocalGradient;
		array <double>^ m_arrWeight;


	public:
		Neuron();
		void LocalField();
		void SignalError();
		void SignalOutput();

};

