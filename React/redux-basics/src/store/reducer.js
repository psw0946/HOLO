const initialState = {
  counter: 0,
  results: [],
};

const reducer = (state=initialState, action) => {
  switch (action.type) {
    case 'INCREMENT':
      const newState = Object.assign({}, state);
      newState.counter = state.counter + 1;
      return newState;
    case 'DECREMENT':
      return {
        ...state,
        counter: state.counter - 1,
      };
    case 'ADD':
      return {
        ...state,
        counter: state.counter + action.val,
      };
    case 'SUBTRACT':
      return {
        ...state,
        counter: state.counter - action.val,
      };
    case 'STORE_RESULT':
      return {
        ...state,
        results: state.results.concat({id: new Date(), value: state.counter}), // concat 은 새로운 array 를 만들어내기 때문에 immutable 하다. (push 절대 쓰면 안됨)
      }
    case 'DELETE_RESULT':
      // const id = 2;
      // const newArray = [...state.results];
      // newArray.splice(id, 1);
      const updatedArray = state.results.filter(result => result.id !== action.resultElId); // filter 도 새로운 array 를 만들어줌.
      return {
        ...state,
        results: updatedArray,
      }
  }
  return state;
};

export default reducer;
