import { useState } from 'react'
import InputBox from './components/input'
import useCurrencyconvInfo from './hooks/currencyconv'

function App() {
  const [amount, setAmount] = useState(0)
  const [from, setFrom] = useState("usd")
  const [to, setTo] = useState("inr")
  const [convertedAmount, setconvertedAmount] = useState(0)

  const currencyInfo = useCurrencyconvInfo(from)
  const options = Object.keys(currencyInfo)

  const swap = () => {
    setFrom(to)
    setTo(from)
    setAmount(convertedAmount)
    setconvertedAmount(amount)
  }

  const convert = () => {
    if (currencyInfo[to]) {
      setconvertedAmount(amount * currencyInfo[to])
    }
  }

  return (
    <div
      className="w-full h-screen flex justify-center items-center bg-cover"
      style={{
        backgroundImage: `url('https://images.pexels.com/photos/316401/pexels-photo-316401.jpeg')`,
      }}
    >
      <div className="w-full max-w-md mx-auto border rounded-lg p-5 bg-white/30 backdrop-blur-sm">
        <form
          onSubmit={(e) => {
            e.preventDefault()
            convert()
          }}
        >
          {/* FROM */}
          <InputBox
            label="From"
            amount={amount}
            currencyOptions={options}
            selectCurrency={from}
            onCurrencyChange={(currency) => setFrom(currency)}
            onAmountChange={(amount) => setAmount(amount)}
          />

          {/* SWAP BUTTON */}
          <div className="relative w-full h-0.5 my-4">
            <button
              type="button"
              className="absolute left-1/2 -translate-x-1/2 -translate-y-1/2 bg-blue-600 text-white px-3 py-1 rounded"
              onClick={swap}
            >
              Swap
            </button>
          </div>

          {/* TO */}
          <InputBox
            label="To"
            amount={convertedAmount}
            currencyOptions={options}
            selectCurrency={to}
            onCurrencyChange={(currency) => setTo(currency)}
            amountDisable
          />

          <button
            type="submit"
            className="w-full bg-blue-600 text-white px-4 py-3 rounded-lg mt-4"
          >
            Convert {from.toUpperCase()} to {to.toUpperCase()}
          </button>
        </form>
      </div>
    </div>
  );
}

export default App
