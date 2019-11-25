import React from 'react';

class ErrorBoundary extends React.Component { // production 모드일 때 페이지가 나타난다. (개발 서버에서는 overwrite 돼서 기본 디버깅 페이지 출현)
  state = {
    hasError: false,
    errorMessage: '',
  };

  componentDidCatch = (error, errorInfo) => {
    this.setState({
      hasError: true,
      errorMessage: error,
    });
  };

  render() {
    if (this.state.hasError) {
      return <h1>Something went wrong</h1>;
    } else {
      return this.props.children;
    }
  }
}

export default ErrorBoundary;
